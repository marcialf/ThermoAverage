
 
// include the ThermoAverage library
#include <ThermoAverage.h>

// create a ThermoAverage instance, reading from analog pin A0
// Using a 10K thermistor and 10K serie resistor.
ThermoAverage thermoAverage(A0);

// If you have a different type of thermistor, resistor or beta coefficiente
/* ThermoAverage thermoAverage(A0,            // the analog pin to read from
                             10000,           // the nominal resistance
                             10000,           // the series resistance
                             3950,            // the beta coefficient of the thermistor
                             25,              // the temperature for nominal resistance
                             false);          // false to 5 V AREF and true to 3.3 V AREF 
*/

void setup() {

  // set up UART
  Serial.begin(9600);

}

void loop() {
  
  // print the temperature
  Serial.print("Temperature = ");
  Serial.println(thermoAverage.temperature(10));   // calculate 10 sample average

  // pause for a second
  delay(1000);
}
