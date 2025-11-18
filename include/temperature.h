#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <string>

class TemperatureConverter {
public:
    static double convert(const std::string& fromUnit, const std::string& toUnit, double value);
    
    static std::string getSupportedUnits();

private:
    
    static double celsiusToFahrenheit(double celsius);
    static double celsiusToKelvin(double celsius);
    static double fahrenheitToCelsius(double fahrenheit);
    static double fahrenheitToKelvin(double fahrenheit);
    static double kelvinToCelsius(double kelvin);
    static double kelvinToFahrenheit(double kelvin);
};

#endif // TEMPERATURE_H