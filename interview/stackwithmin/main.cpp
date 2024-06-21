#include <iostream>
#include <stack>
#include <assert.h>

using namespace std;

template <class T>
class StackWithMin
{
public:
    StackWithMin() { }
    ~StackWithMin() { }
    T &top() { return m_data.top(); }
    const T &top() const { return m_data.top(); }
    void push(const T &value)
    {
        m_data.push(value);
        if (m_min.size() == 0 || m_min.top() > value)
            m_min.push(value);
        else
            m_min.push(m_min.top());
    }
    void pop()
    {
        assert(m_data.size() > 0 && m_min.size() > 0);

        m_data.pop();
        m_min.pop();
    }
    const T &min() const
    {
        assert(m_data.size() > 0 && m_min.size() > 0);

        return m_min.top();
    }
    bool empty() const { return m_data.empty(); }
    size_t size() const { return m_data.size(); }

private:
    stack<T> m_data;
    stack<T> m_min;
};

int main()
{
    return 0;
}
