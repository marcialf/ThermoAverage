
#include "Arduino.h"
#include "ThermoAverage.h"
#include <math.h>

ThermoAverage::ThermoAverage(uint8_t analogPin, uint32_t thermistorResistance, uint32_t seriesResistance,
                             uint16_t betaCoefficient, uint8_t nominalTemperature, bool aref) {

    _analogPin = analogPin;
    _thermistorResistance = thermistorResistance;
    _seriesResistance = seriesResistance;
    _betaCoefficient = betaCoefficient;
    _nominalTemperature = nominalTemperature;
    analogReference(aref? EXTERNAL: DEFAULT);     // set analog reference to 5 V or 3.3 V
	}
	
float ThermoAverage::temperature(void) {	
    return temperature(1);
}
	
float ThermoAverage::temperature(uint8_t _samples) {

    // take temperature samples
    float average = 0;
 
    for (uint8_t i = 0; i < _samples; i++) {
        average += analogRead(_analogPin);
        delay(10);
    }
    average /= _samples;

    // convert ADC value to resistance
    average = _seriesResistance * ((pow(2.0, ADC_SIZE) - 1) / average - 1);

    // Steinhart–Hart equation
    float steinhart = (log(average / _thermistorResistance)) / _betaCoefficient;
    steinhart += 1.0 / (_nominalTemperature + 273.15);
    steinhart = 1.0 / steinhart; 
    steinhart -= 273.15; 

    return steinhart;
}