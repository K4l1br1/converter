#include "../include/distance.h"
#include <stdexcept>
#include <algorithm>

using namespace std;

double DistanceConverter::convert(const string& fromUnit, const string& toUnit, double value) {
    double meters = toMeters(fromUnit, value);
    return fromMeters(toUnit, meters);
}

string DistanceConverter::getSupportedUnits() {
    return "m (метры), km (километры), mi (мили), ft (футы)";
}

double DistanceConverter::toMeters(const string& unit, double value) {
    string unitLower = unit;
    transform(unitLower.begin(), unitLower.end(), unitLower.begin(), ::tolower);
    
    if (unitLower == "m" || unitLower == "м") {
        return value;
    } else if (unitLower == "km" || unitLower == "км") {
        return value * 1000.0;
    } else if (unitLower == "mi") {
        return value * 1609.34;
    } else if (unitLower == "ft") {
        return value * 0.3048;
    } else {
        throw invalid_argument("Неизвестная единица расстояния: " + unit);
    }
}

double DistanceConverter::fromMeters(const string& unit, double value) {
    string unitLower = unit;
    transform(unitLower.begin(), unitLower.end(), unitLower.begin(), ::tolower);
    
    if (unitLower == "m" || unitLower == "м") {
        return value;
    } else if (unitLower == "km" || unitLower == "км") {
        return value / 1000.0;
    } else if (unitLower == "mi") {
        return value / 1609.34;
    } else if (unitLower == "ft") {
        return value / 0.3048;
    } else {
        throw invalid_argument("Неизвестная единица расстояния: " + unit);
    }
}
