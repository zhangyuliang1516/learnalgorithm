#include <iostream>
#include <vector>

using namespace std;

template <class T>
class DynamicArray
{
public:
    void insert(T num)
    {
        if (((min.size() + max.size()) & 1) == 0) {
            if (max.size() > 0 && num < max[0]) {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<T>());
                num = max[0];
                pop(max.begin(), max.end(), less<T>());
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<T>());
        } else {
            if (min.size() > 0 && num > min[0]) {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<T>());
                num = min[0];
                pop_heap(min.begin(), min.end(), greater<T>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<T>());
        }
    }
    T getMedian()
    {
        int size = min.size() + max.size();
        if (size == 0)
            throw exception("No numbers are avaliable!");
        if ((size & 1) == 0)
            return (min[0] + max[0]) / 2;
        else
            return min[0];
    }

private:
    vector<T> min;
    vector<T> max;
};

int main()
{
    return 0;
}
