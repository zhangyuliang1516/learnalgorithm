#include <iostream>
#include <mutex>

using namespace std;

class Singleton1
{
public:
    static Singleton1 *instance() { return &_singleton1; }

private:
    Singleton1() { }
    static Singleton1 _singleton1;
};

Singleton1 Singleton1::_singleton1;

// thread safe in C++11
class Singleton2
{
public:
    static Singleton2 *instance()
    {
        static Singleton2 _singleton2;
        return &_singleton2;
    }

private:
    Singleton2();
};
class Singleton3
{
public:
    static Singleton3 *instance()
    {
        if (_singleton3 == nullptr) {
            lock_guard<mutex> lock(_mutex);
            if (_singleton3 == nullptr) {
                _singleton3 = new Singleton3;
            }
        }
        return _singleton3;
    }

private:
    Singleton3();
    static Singleton3 *_singleton3;
    static mutex _mutex;
};
Singleton3 *Singleton3::_singleton3 = nullptr;
mutex Singleton3::_mutex;

int main()
{
    auto p1 = Singleton1::instance();
    auto p2 = Singleton1::instance();
    cout << (p1 == p2) << endl;
    return 0;
}
