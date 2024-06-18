#include <iostream>
#include <stack>
#include <exception>

using namespace std;

template <class T>
class CQueue
{
public:
    CQueue() { }
    ~CQueue() { }
    void append(const T &value) { stack1.push(value); }
    T remove()
    {
        if (stack2.size() <= 0) {
            while (stack1.size() > 0) {
                T value = stack1.top();
                stack2.push(value);
                stack1.pop();
            }
        }
        if (stack2.size() <= 0)
            throw exception("Queue is empty!");
        T value = stack2.top();
        stack2.pop();
        return value;
    }

private:
    stack<T> stack1;
    stack<T> stack2;
};

void test(char actual, char expected)
{
    if (actual == expected)
        cout << "Passed" << endl;
    else
        cout << "failed" << endl;
}

int main()
{
    CQueue<char> queue;
    queue.append('a');
    queue.append('b');
    queue.append('c');

    char a = queue.remove();
    test(a, 'a');
    char b = queue.remove();
    test(b, 'b');

    queue.append('d');

    char c = queue.remove();
    test(c, 'c');
    char d = queue.remove();
    test(d, 'd');
    try {
        char e = queue.remove();
        test(e, 'e');
    } catch (exception &e) {
        cout << e.what() << endl;
    }

    return 0;
}
