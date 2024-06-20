#include <iostream>
#include <exception>

using namespace std;

bool scanUnsignedInterger(const char **str)
{
    const char *before = *str;
    while (**str != '\0' && **str >= '0' && **str <= '9')
        (*str)++;
    return *str > before;
}
bool scanInterger(const char **str)
{
    if (**str == '+' || **str == '-')
        (*str)++;
    return scanUnsignedInterger(str);
}
bool isNumeric(const char *str)
{
    if (str == nullptr)
        return false;
    bool numeric = scanInterger(&str);
    if (*str == '.') {
        str++;
        numeric = scanUnsignedInterger(&str) || numeric;
    }
    if (*str == 'e' || *str == 'E') {
        str++;
        numeric = scanInterger(&str) && numeric;
    }
    return numeric && (*str == '\0');
}

int main()
{
    return 0;
}
