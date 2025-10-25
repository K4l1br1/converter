#include "converter.h"
#include "include/distance.h"
#include "include/weight.h"
#include "include/temperature.h"
#include <iostream>
#include <stdexcept>

using namespace std;

UnitConverter::UnitConverter() {
}

UnitConverter::~UnitConverter() {
}

double UnitConverter::convert(ConversionType type, const string& fromUnit, 
                               const string& toUnit, double value) {
    switch (type) {
        case ConversionType::DISTANCE:
            return DistanceConverter::convert(fromUnit, toUnit, value);
        
        case ConversionType::WEIGHT:
            return WeightConverter::convert(fromUnit, toUnit, value);
        
        case ConversionType::TEMPERATURE:
            return TemperatureConverter::convert(fromUnit, toUnit, value);
        
        default:
            throw invalid_argument("Неизвестный тип конвертации");
    }
}

string UnitConverter::getAvailableUnits(ConversionType type) const {
    switch (type) {
        case ConversionType::DISTANCE:
            return DistanceConverter::getSupportedUnits();
        
        case ConversionType::WEIGHT:
            return WeightConverter::getSupportedUnits();
        
        case ConversionType::TEMPERATURE:
            return TemperatureConverter::getSupportedUnits();
        
        default:
            return "Неизвестно";
    }
}

void UnitConverter::displayMenu() const {
    cout << "\\n--- МЕНЮ ---" << endl;
    cout << "1. Конвертация расстояния" << endl;
    cout << "2. Конвертация веса" << endl;
    cout << "3. Конвертация температуры" << endl;
    cout << "0. Выход" << endl;
}

string UnitConverter::conversionTypeToString(ConversionType type) const {
    switch (type) {
        case ConversionType::DISTANCE: return "Расстояние";
        case ConversionType::WEIGHT: return "Вес";
        case ConversionType::TEMPERATURE: return "Температура";
        default: return "Неизвестно";
    }
}
