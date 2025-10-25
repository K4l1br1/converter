#ifndef DISTANCE_H
#define DISTANCE_H

#include <string>

class DistanceConverter {
public:
    static double convert(const std::string& fromUnit, const std::string& toUnit, double value);
    
    static std::string getSupportedUnits();

private:
    static double toMeters(const std::string& unit, double value);
    
    static double fromMeters(const std::string& unit, double value);
};

#endif
