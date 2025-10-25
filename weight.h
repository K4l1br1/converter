#pragma once
#ifndef WEIGHT_H
#define WEIGHT_H

#include <string>

class WeightConverter {
public:
    // Конвертация веса
    static double convert(const std::string& fromUnit, const std::string& toUnit, double value);

    // Список поддерживаемых единиц
    static std::string getSupportedUnits();

private:
    // Базовые конвертации в килограммы
    static double toKilograms(const std::string& unit, double value);

    // Конвертация из килограммов в другие единицы
    static double fromKilograms(const std::string& unit, double value);
};

#endif // WEIGHT_H