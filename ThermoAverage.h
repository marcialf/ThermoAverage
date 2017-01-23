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

#ifndef ThermoAverage_h
#define ThermoAverage_h

#include "Arduino.h"

#define DEFAULT_NOMINAL_RESISTANCE	10000
#define DEFAULT_SERIES_RESISTANCE	10000
#define DEFAULT_BETA_COEFFICIENT	3435
#define DEFAULT_NOMINAL_TEMPERATURE	25
#define AREF				0
#define ADC_SIZE			10
#define DEFAULT_SAMPLE_SIZE		10  

class ThermoAverage {
  public:

    /**
     * @param analogPin          The analog pin where the thermistor is connected to.
     * @param adcSize            The ADC size. This is usually ADC_SIZE_10_BIT.
     * @param nominalResistance  The nominal resistance at 25 degrees celsius.
     * @param seriesResistance   The value of the series resistor.
     * @param betaCoefficient    The beta coefficient of the thermistor.
     * @param nominalTemperature The temperature for nominal resistance. This is usually 25.
     * @param samples            The number of samples to take for temperature smoothing.
     */
    ThermoAverage(uint8_t analogPin,
                  uint32_t thermistorResistance = DEFAULT_NOMINAL_RESISTANCE,
                  uint32_t seriesResistance = DEFAULT_SERIES_RESISTANCE,
                  uint16_t betaCoefficient = DEFAULT_BETA_COEFFICIENT,
                  uint8_t nominalTemperature = DEFAULT_NOMINAL_TEMPERATURE,
		  bool useSREF = AREF);

    float temperature(void);
 
   /**
     * @param samples            The number of samples to take for temperature smoothing.
     */
    float temperature(uint8_t samples);
	
  private:

     uint8_t  _analogPin;
     uint32_t _thermistorResistance;
     uint32_t _seriesResistance;
     uint16_t _betaCoefficient;
     uint8_t  _nominalTemperature;
};

#endif
