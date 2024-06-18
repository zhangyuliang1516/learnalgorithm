#include <iostream>
#include <exception>

using namespace std;

long long fibonacci1(unsigned int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci1(n - 1) + fibonacci1(n - 2);
}

long long fibonacci2(unsigned int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    long long fibNMinusOne = 1;
    long long fibNMinusTwo = 0;
    long long fibN = 0;
    for (int i = 2; i <= n; ++i) {
        fibN = fibNMinusOne + fibNMinusTwo;
        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }
    return fibN;
}

struct Matrix2By2
{
    Matrix2By2(long long m00, long long m01, long long m10, long long m11)
        : m00(m00)
        , m01(m01)
        , m10(m10)
        , m11(m11)
    {
    }
    long long m00;
    long long m01;
    long long m10;
    long long m11;
};

Matrix2By2 matrixMultiply(const Matrix2By2 &m1, const Matrix2By2 &m2)
{
    return Matrix2By2(m1.m00 * m2.m00 + m1.m01 * m2.m10, m1.m00 * m2.m01 + m1.m01 * m2.m11,
                      m1.m10 * m2.m00 + m1.m11 * m2.m10, m1.m10 * m2.m01 + m1.m11 * m2.m11);
}

Matrix2By2 matrixPower(int n)
{
    if (n == 1) {
        return Matrix2By2(1, 1, 1, 0);
    } else if ((n & 1) == 0) {
        Matrix2By2 m = matrixPower(n / 2);
        return matrixMultiply(m, m);
    } else {
        Matrix2By2 m = matrixPower(n / 2);
        m = matrixMultiply(m, m);
        return matrixMultiply(m, Matrix2By2(1, 1, 1, 0));
    }
}

long long fibonacci3(unsigned int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    Matrix2By2 m = matrixPower(n - 1);
    return m.m00;
}

void test(unsigned int n, long long expected)
{
    if (fibonacci1(n) == expected)
        cout << "fibonacci1(" << n << ") passed" << endl;
    else
        cout << "fibonacci1(" << n << ") failed" << endl;
    if (fibonacci2(n) == expected)
        cout << "fibonacci2(" << n << ") passed" << endl;
    else
        cout << "fibonacci2(" << n << ") failed" << endl;
    if (fibonacci3(n) == expected)
        cout << "fibonacci3(" << n << ") passed" << endl;
    else
        cout << "fibonacci3(" << n << ") failed" << endl;
}

int main()
{
    test(0, 0);
    test(1, 1);
    test(2, 1);
    test(3, 2);
    test(4, 3);
    test(5, 5);
    test(6, 8);
    test(7, 13);
    test(8, 21);
    test(9, 34);
    test(10, 55);

    test(40, 102334155);
    return 0;
}
