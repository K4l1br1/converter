#pragma once
#ifndef WEIGHT_H
#define WEIGHT_H

#include <string>

class WeightConverter {
public:
    
    static double convert(const std::string& fromUnit, const std::string& toUnit, double value);

    static std::string getSupportedUnits();

private:
    static double toKilograms(const std::string& unit, double value);

    static double fromKilograms(const std::string& unit, double value);
};

#endif // WEIGHT_H