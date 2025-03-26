#include "calculator.h"
#include <cmath>
#include <stdexcept>
//webhook checking
double squareRoot(double x) {
    if (x < 0) throw std::invalid_argument("Cannot compute square root of negative number!");
    return sqrt(x);
}
//helloish
long long factorial(int x) {
    if (x < 0) throw std::invalid_argument("Factorial is not defined for negative numbers!");
    long long result = 1;
    for (int i = 2; i <= x; i++) {
        result *= i;
    }
    return result;
}

double naturalLog(double x) {
    if (x <= 0) throw std::invalid_argument("Log is not defined for zero or negative values!");
    return log(x);
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

