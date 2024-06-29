#include <iostream>
#include <exception>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxInSlidingWindow(const vector<int> &nums, unsigned int size)
{
    vector<int> maxInWindows;
    if (nums.size() >= 0 && size >= 1) {
        deque<int> indexs;
        for (int i = 0;  i< size; ++i) {
            while (!indexs.empty() && nums[i] > nums[indexs.back()])
                indexs.pop_back();
            indexs.push_back(i);
        }
        for (int i = size; i < nums.size(); ++i) {
            maxInWindows.push_back(nums[indexs.front()]);
            while (!indexs.empty() && nums[i] > nums[indexs.back()])
                indexs.pop_back();

            if (!indexs.empty() && indexs.front() < (i - size))
                indexs.pop_front();
            indexs.push_back(i);
        }
        maxInWindows.push_back(nums[indexs.front()]);
    }
    return maxInWindows;
}

template<class T> class QueueWithMax
{
public:
    QueueWithMax()
        : currentIndex(0)
    {}
    void push_back(T num)
    {
        while (!maxs.empty() && maxs.back().num < num)
            maxs.pop_back();
        InternalData internalData = {num, currentIndex};
        datas.push_back(internalData);
        maxs.push_back(internalData);
        ++currentIndex;
    }
    void pop_front()
    {
        if (maxs.empty())
            throw exception("queue is empty");
        if (maxs.front().index == datas.front().index)
            maxs.pop_front();
        datas.pop_front();
    }
    T max() const
    {
        if (maxs.empty())
            throw exception("queue is empty");
        return maxs.front().num;
    }
private:
    struct InternalData
    {
        T num;
        int index;
    };
    deque<InternalData> datas;
    deque<InternalData> maxs;
    int currentIndex;
};

int main()
{
    return 0;
}
