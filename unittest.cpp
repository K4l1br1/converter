#include <gtest/gtest.h>
#include "converter.h"
#include "distance.h"
#include "weight.h"
#include "temperature.h"

TEST(DistanceConversionTest, MetersToKilometers) {
    double meters = 1500.0;
    double expected_km = 1.5;
    double result = DistanceConverter::ConvertMetersToKilometers(meters);
    EXPECT_DOUBLE_EQ(result, expected_km);
}

TEST(WeightConversionTest, KilogramsToPounds) {
    double kg = 2.0;
    double expected_lb = 4.40925; // 1 kg = 2.20462 lb
    double result = WeightConverter::ConvertKilogramsToPounds(kg);
    EXPECT_NEAR(result, expected_lb, 1e-5);
}

TEST(TemperatureConversionTest, CelsiusToFahrenheit) {
    double c = 0.0;
    double expected_f = 32.0;
    double result = TemperatureConverter::ConvertCelsiusToFahrenheit(c);
    EXPECT_DOUBLE_EQ(result, expected_f);
}
