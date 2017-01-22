# ThermoAverage
Calculate Temperature with Thermistor taking the average of measured samples. 

### Requirements

Hardware: This library was developed to Arduino AVR 

Boards tested:

```
Arvuino Uno
Arduino Nano 328/168
Arduino Mini
```

Software: Any Arduino IDE >= 1.3.0 should be fine

### Hardware Installation

The ThermoAverage use any Analog Input.

The VCC can be 5 V or 3.3 V (better...).

![thermistor](https://github.com/marcialf/ThermoAverage/thermistor.PNG)

[[https://github.com/marcialf/ThermoAverage/thermistor.PNG|alt=thermistor]]


### Library Installation

1. Download the ZIP file from https://github.com/marcialf/ThermoAverage/archive/master.zip
2. From the Arduino IDE: Sketch -> Include Library... -> Add .ZIP Library...
3. Restart the Arduino IDE to see the new "ThermoAverage" library.

See the comments in the example sketches for details about how to try them out.

```
Give the example
```

And repeat

```
until finished
```

End with an example of getting some data out of the system or using it for a little demo


## Examples

This library including the following example:

[ThermoAverageExample](examples/ThermoAverageExample/ThermoAverageExample.ino): Simple temperature mesuarement with 10 samples.

## Running the tests

Explain how to run the automated tests for this system

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```


## Built With

* [Arduino IDE](https://www.arduino.cc/en/Main/Software) - The Arduino IDE

## Authors

* **Marcial Fernandez** - *Initial version* - [marcialf](https://github.com/marcialf)

## License

This project is licensed under the GPL License - see the [LICENSE](LICENSE) file for details.
