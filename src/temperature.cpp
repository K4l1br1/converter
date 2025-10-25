#include "../include/temperature.h"
#include <stdexcept>
#include <algorithm>

using namespace std;

double TemperatureConverter::convert(const string& fromUnit, const string& toUnit, double value) {
    string fromLower = fromUnit;
    string toLower = toUnit;
    transform(fromLower.begin(), fromLower.end(), fromLower.begin(), ::tolower);
    transform(toLower.begin(), toLower.end(), toLower.begin(), ::tolower);
    
    // Celsius conversions
    if (fromLower == "c" || fromLower == "celsius" || fromLower == "ц") {
        if (toLower == "f" || toLower == "fahrenheit" || toLower == "ф") {
            return celsiusToFahrenheit(value);
        } else if (toLower == "k" || toLower == "kelvin" || toLower == "к") {
            return celsiusToKelvin(value);
        } else if (toLower == "c" || toLower == "celsius" || toLower == "ц") {
            return value;
        }
    }
    // Fahrenheit conversions
    else if (fromLower == "f" || fromLower == "fahrenheit" || fromLower == "ф") {
        if (toLower == "c" || toLower == "celsius" || toLower == "ц") {
            return fahrenheitToCelsius(value);
        } else if (toLower == "k" || toLower == "kelvin" || toLower == "к") {
            return fahrenheitToKelvin(value);
        } else if (toLower == "f" || toLower == "fahrenheit" || toLower == "ф") {
            return value;
        }
    }
    // Kelvin conversions
    else if (fromLower == "k" || fromLower == "kelvin" || fromLower == "к") {
        if (toLower == "c" || toLower == "celsius" || toLower == "ц") {
            return kelvinToCelsius(value);
        } else if (toLower == "f" || toLower == "fahrenheit" || toLower == "ф") {
            return kelvinToFahrenheit(value);
        } else if (toLower == "k" || toLower == "kelvin" || toLower == "к") {
            return value;
        }
    }
    
    throw invalid_argument("Неизвестная единица температуры: " + fromUnit + " или " + toUnit);
}

string TemperatureConverter::getSupportedUnits() {
    return "C (Цельсий), F (Фаренгейт), K (Кельвин)";
}

double TemperatureConverter::celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double TemperatureConverter::celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double TemperatureConverter::fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double TemperatureConverter::fahrenheitToKelvin(double fahrenheit) {
    return celsiusToKelvin(fahrenheitToCelsius(fahrenheit));
}

double TemperatureConverter::kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double TemperatureConverter::kelvinToFahrenheit(double kelvin) {
    return celsiusToFahrenheit(kelvinToCelsius(kelvin));
}