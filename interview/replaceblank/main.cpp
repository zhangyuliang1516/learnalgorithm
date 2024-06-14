#include <iostream>

using namespace std;

void replaceBlank(char str[], int length)
{
    if (str == nullptr || length <= 0)
        return;
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while (str[i] != '\0') {
        originalLength++;
        if (str[i] == ' ')
            numberOfBlank++;
        i++;
    }
    int newLength = originalLength + numberOfBlank * 2;
    if (newLength > length)
        return;
    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {
        if (str[indexOfOriginal] == ' ') {
            str[indexOfNew--] = '0';
            str[indexOfNew--] = '2';
            str[indexOfNew--] = '%';
        } else {
            str[indexOfNew--] = str[indexOfOriginal];
        }
        indexOfOriginal--;
    }
}

void test(const char *testName, char str[], int length, const char *expected)
{
    cout << testName << " begin: ";
    replaceBlank(str, length);
    if (str == nullptr && expected == nullptr)
        cout << "passed" << endl;
    else if (strcmp(str, expected) == 0)
        cout << "passed" << endl;
    else
        cout << "failed" << endl;
}

void test1()
{
    char str[100] = "Hello world";
    test("Test1", str, 100, "Hello%20world");
}

void test2()
{
    char str[100] = " Helloworld";
    test("Test2", str, 100, "%20Helloworld");
}

void test3()
{
    char str[100] = "Helloworld ";
    test("Test3", str, 100, "Helloworld%20");
}

void test4()
{
    char str[100] = "Hello  world";
    test("Test4", str, 100, "Hello%20%20world");
}

void test5()
{
    char str[100] = "we are happy";
    test("Test5", str, 100, "we%20are%20happy");
}

void test6()
{
    test("Test6", nullptr, 100, nullptr);
}

void test7()
{
    char str[100] = "";
    test("Test7", str, 100, "");
}

void test8()
{
    char str[100] = " ";
    test("Test8", str, 100, "%20");
}

void test9()
{
    char str[100] = "    ";
    test("Test9", str, 100, "%20%20%20%20");
}

void test10()
{
    char str[100] = "Helloworld";
    test("Test10", str, 100, "Helloworld");
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test5();
    test7();
    test8();
    test9();
    test10();
    return 0;
}
