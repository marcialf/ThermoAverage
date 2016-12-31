/*
* ThermoAverage.cc - library for thermistor average
  
  Copyright (c) Marcial Fernandez 2016
  
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
