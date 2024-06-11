#include <cstring>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

class CString
{
public:
    CString(const char *data = nullptr);
    CString(const CString &other);
    ~CString();

    CString &operator=(const CString &other);
    void print();

private:
    char *m_data { nullptr };
};

CString::CString(const char *data)
{
    if (data) {
        int len = strlen(data);
        m_data = new char[len + 1];
        strcpy_s(m_data, len + 1, data);
    } else {
        m_data = new char[1];
        m_data[0] = '\0';
    }
}
CString::CString(const CString &other)
{
    int len = strlen(other.m_data);
    m_data = new char[len + 1];
    strcpy_s(m_data, len + 1, other.m_data);
}
CString::~CString()
{
    if (m_data) {
        delete[] m_data;
        m_data = nullptr;
    }
}
CString &CString::operator=(const CString &other)
{
    if (&other == this)
        return *this;
    if (m_data)
        delete[] m_data;
    int len = strlen(other.m_data);
    m_data = new char[len + 1];
    strcpy_s(m_data, len + 1, other.m_data);
    return *this;
}
void CString::print()
{
    cout << m_data;
}

void test1()
{
    cout << "Test1 begin" << endl;
    char *text = "Hello, world!";
    CString str1(text);
    CString str2;
    str2 = str1;
    cout << "The expected result is: " << text << endl;
    cout << "The actual result is: ";
    str2.print();
    cout << endl;
}
void test2()
{
    cout << "Test2 begin" << endl;
    char *text = "Hello, world!";
    CString str1(text);
    str1 = str1;
    cout << "The expected result is: " << text << endl;
    cout << "The actual result is: ";
    str1.print();
    cout << endl;
}
void test3()
{
    cout << "Test3 begin" << endl;
    char *text = "Hello, world!";
    CString str1(text);
    CString str2, str3;
    str3 = str2 = str1;
    cout << "The expected result is: " << text << endl;
    cout << "str2 actual result is: ";
    str2.print();
    cout << endl;
    cout << "The expected result is: " << text << endl;
    cout << "str3 actual result is: ";
    str3.print();
    cout << endl;
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}
