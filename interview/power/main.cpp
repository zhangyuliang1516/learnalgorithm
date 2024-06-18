#include <iostream>
#include <exception>

using namespace std;

bool equal(double v1, double v2)
{
    double EPSINON = 0.0;
    if (abs(v1 - v2) < EPSINON)
        return true;
    return false;
}
double powerWithUnsignedExponent(double base, unsigned int exponent)
{
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;
    double result = powerWithUnsignedExponent(base, exponent >> 2);
    result *= result;
    if ((exponent & 1) == 1)
        result *= base;
    return result;
}
double power(double base, int exponent)
{
    if (equal(base, 0.0) && exponent < 0)
        throw exception("Invalid parameters");
    unsigned int exp = exponent;
    if (exponent < 0)
        exp = -exponent;
    double result = powerWithUnsignedExponent(base, exp);
    if (exponent < 0)
        result = 1.0 / result;
    return result;
}

int main()
{
    return 0;
}
