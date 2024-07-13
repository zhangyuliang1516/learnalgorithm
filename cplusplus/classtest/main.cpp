#include <iostream>

using namespace std;

class test
{
public:
    test() { cout << "default constructor" << endl; }
    test(int value)
        : value(value)
    {
        cout << "constructor " << value << endl;
    }
    test(const test &t)
        : value(t.value)
    {
        cout << "copy constructor " << value << endl;
    }
    ~test() { cout << "destructor " << value << endl; }
    test &operator=(const test &t)
    {
        cout << "assignment " << t.value << endl;
        if (this == &t)
            return *this;
        value = t.value;
        return *this;
    }

private:
    int value;
};

int main()
{
    test t1;
    test t2(10);
    test t3(20);
    test t4 = t3;
    test t5 = 30;
    test t6 = 40 + 50;

    /*
    default constructor
    constructor 10
    constructor 20
    copy constructor 20
    constructor 30
    constructor 90
    destructor 90
    destructor 30
    destructor 20
    destructor 20
    destructor 10
    destructor -858993460
     */
    return 0;
}
