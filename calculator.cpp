#include "calculator.h"
#include <stdexcept>

double Calculator::squareRoot(double x) {
    if (x < 0) throw std::invalid_argument("Negative input");
    return sqrt(x);
}

long long Calculator::factorial(int x) {
    if (x < 0) throw std::invalid_argument("Negative input");
    long long result = 1;
    for (int i = 1; i <= x; ++i) {
        result *= i;
    }
    return result;
}

double Calculator::naturalLog(double x) {
    if (x <= 0) throw std::invalid_argument("Input must be positive");
    return log(x);
}

double Calculator::power(double base, double exponent) {
    return pow(base, exponent);
}
