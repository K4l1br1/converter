#include <iostream>
#include <cmath>
#include <stdexcept>
#include <functional>

#include "../include/distance.h"
#include "../include/weight.h"
#include "../include/temperature.h"

static bool close(double a, double b, double eps = 1e-6) {
    return std::fabs(a - b) <= eps;
}

static int tests_passed = 0;
static int tests_failed = 0;

static void expect_equal(double got, double want, const char* msg) {
    if (!close(got, want)) {
        std::cerr << "FAILED: " << msg << " | got=" << got << " want=" << want << std::endl;
        ++tests_failed;
    } else {
        ++tests_passed;
    }
}

static void expect_throws_invalid(const std::function<void()>& f, const char* msg) {
    try {
        f();
        std::cerr << "FAILED (no throw): " << msg << std::endl;
        ++tests_failed;
    } catch (const std::invalid_argument&) {
        ++tests_passed;
    } catch (...) {
        std::cerr << "FAILED (wrong exception): " << msg << std::endl;
        ++tests_failed;
    }
}

void test_distance() {
    std::cout << "Running distance tests...\n";
    expect_equal(
        DistanceConverter::convert("m", "km", 1500),
        1.5,
        "1500 m -> 1.5 km"
    );

    expect_equal(
        DistanceConverter::convert("mi", "m", 1),
        1609.34,
        "1 mi -> 1609.34 m"
    );

    expect_equal(
        DistanceConverter::convert("ft", "m", 3.2808399),
        1.0,
        "~3.2808399 ft -> 1 m"
    );

    expect_throws_invalid([](){ DistanceConverter::convert("unknown", "m", 1); }, "unknown from unit");
    expect_throws_invalid([](){ DistanceConverter::convert("m", "unknown", 1); }, "unknown to unit");
}

void test_weight() {
    std::cout << "Running weight tests...\n";
    expect_equal(
        WeightConverter::convert("kg", "g", 2.5),
        2500.0,
        "2.5 kg -> 2500 g"
    );

    expect_equal(
        WeightConverter::convert("lb", "kg", 2.2046226218),
        1.0,
        "~2.2046226218 lb -> 1 kg"
    );

    expect_equal(
        WeightConverter::convert("t", "kg", 0.5),
        500.0,
        "0.5 t -> 500 kg"
    );

    expect_throws_invalid([](){ WeightConverter::convert("unknown", "kg", 1); }, "unknown from unit");
    expect_throws_invalid([](){ WeightConverter::convert("kg", "unknown", 1); }, "unknown to unit");
}

void test_temperature() {
    std::cout << "Running temperature tests...\n";
    expect_equal(
        TemperatureConverter::convert("C", "F", 0.0),
        32.0,
        "0°C -> 32°F"
    );

    expect_equal(
        TemperatureConverter::convert("F", "C", 32.0),
        0.0,
        "32°F -> 0°C"
    );

    expect_equal(
        TemperatureConverter::convert("K", "C", 273.15),
        0.0,
        "273.15 K -> 0°C"
    );

    expect_equal(
        TemperatureConverter::convert("C", "K", -273.15),
        0.0,
        "-273.15°C -> 0 K (edge)"
    );

    expect_throws_invalid([](){ TemperatureConverter::convert("unknown", "C", 1); }, "unknown from unit");
    expect_throws_invalid([](){ TemperatureConverter::convert("C", "unknown", 1); }, "unknown to unit");
}

int main() {
    test_distance();
    test_weight();
    test_temperature();

    std::cout << "\nTests passed: " << tests_passed << "\n";
    std::cout << "Tests failed: " << tests_failed << "\n";

    if (tests_failed == 0) {
        std::cout << "ALL TESTS OK\n";
        return 0;
    } else {
        std::cout << "SOME TESTS FAILED\n";
        return 1;
    }
}
