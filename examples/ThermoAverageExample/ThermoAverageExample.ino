/*
* ThermoAverage.h - library for thermistor average
  
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
