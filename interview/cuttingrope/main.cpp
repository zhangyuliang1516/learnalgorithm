#include <iostream>
#include <exception>

using namespace std;

int maxProductAfterCutting1(int length)
{
    if (length < 2)
        return 0;
    if (length == 2)
        return 1;
    if (length == 3)
        return 2;
    int *products = new int[length + 1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    for (int i = 4; i <= length; ++i) {
        int max = 0;
        for (int j = 1; j < i / 2; ++j) {
            int product = products[j] * products[i - j];
            if (max < product)
                max = product;
        }
        products[i] = max;
    }
    int max = products[length];
    delete[] products;
    return max;
}
int maxProductAfterCutting2(int length)
{
    if (length < 2)
        return 0;
    if (length == 2)
        return 1;
    if (length == 3)
        return 2;
    int timesOf3 = length / 3;
    if (length - timesOf3 * 3 == 1)
        timesOf3 -= 1;
    int timesOf2 = (length - timesOf3 * 3) / 2;
    return pow(3, timesOf3) * pow(2, timesOf2);
}

int main()
{
    return 0;
}
