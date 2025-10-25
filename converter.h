#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>
#include <map>
#include <functional>

class UnitConverter {
public:
    enum class ConversionType {
        DISTANCE,
        WEIGHT,
        TEMPERATURE
    };

    UnitConverter();
    ~UnitConverter();

    double convert(ConversionType type, const std::string& fromUnit, 
                   const std::string& toUnit, double value);

    std::string getAvailableUnits(ConversionType type) const;

    void displayMenu() const;
    
private:
    std::string conversionTypeToString(ConversionType type) const;
};

#endif
