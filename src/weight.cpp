#include "../include/weight.h"
#include <stdexcept>
#include <algorithm>

using namespace std;

double WeightConverter::convert(const string& fromUnit, const string& toUnit, double value) {

    double kilograms = toKilograms(fromUnit, value);
    return fromKilograms(toUnit, kilograms);
}

string WeightConverter::getSupportedUnits() {
    return "kg (����������), g (������), lb (�����), oz (�����), t (�����)";
}

double WeightConverter::toKilograms(const string& unit, double value) {
    string unitLower = unit;
    transform(unitLower.begin(), unitLower.end(), unitLower.begin(), ::tolower);

    if (unitLower == "kg" || unitLower == "��") {
        return value;
    }
    else if (unitLower == "g" || unitLower == "�") {
        return value / 1000.0;
    }
    else if (unitLower == "lb") {
        return value * 0.453592;
    }
    else if (unitLower == "oz") {
        return value * 0.0283495;
    }
    else if (unitLower == "t" || unitLower == "�") {
        return value * 1000.0;
    }
    else {
        throw invalid_argument("����������� ������� ����: " + unit);
    }
}

double WeightConverter::fromKilograms(const string& unit, double value) {
    string unitLower = unit;
    transform(unitLower.begin(), unitLower.end(), unitLower.begin(), ::tolower);

    if (unitLower == "kg" || unitLower == "��") {
        return value;
    }
    else if (unitLower == "g" || unitLower == "�") {
        return value * 1000.0;
    }
    else if (unitLower == "lb") {
        return value / 0.453592;
    }
    else if (unitLower == "oz") {
        return value / 0.0283495;
    }
    else if (unitLower == "t" || unitLower == "�") {
        return value / 1000.0;
    }
    else {
        throw invalid_argument("����������� ������� ����: " + unit);
    }
}
