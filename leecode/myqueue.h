#pragma once

#include <iostream>
#include <algorithm>
#include <queue>

void testPriorityQueue()
{
    std::priority_queue<int> q1;
    std::priority_queue<int, std::vector<int>, std::less<int>> q2;
    std::priority_queue<int, std::vector<int>, std::greater<int>> q3;
    for (int i = 0; i < 10; ++i) {
        q1.push(i);
        q2.push(i);
        q3.push(i);
    }
    std::cout << "q1: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << q1.top() << " ";
        q1.pop();
    }
    std::cout << std::endl;
    std::cout << "q2: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << q2.top() << " ";
        q2.pop();
    }
    std::cout << std::endl;
    std::cout << "q3: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << q3.top() << " ";
        q3.pop();
    }
    std::cout << std::endl;
}

std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
{
    std::vector<int> ans;
    std::priority_queue<std::pair<int, int>> q;
    for (int i = 0; i < k; ++i)
        q.emplace(nums[i], i);
    ans.push_back(q.top().first);
    for (int i = k; i < nums.size(); ++i) {
        q.emplace(nums[i], i);
        while (q.top().second <= i - k)
            q.pop();
        ans.push_back(q.top().first);
    }
    return ans;
}

std::vector<int> maxSlidingWindow2(std::vector<int> &nums, int k)
{
    std::vector<int> ans;
    std::deque<int> q;
    for (int i = 0; i < k; ++i) {
        while (!q.empty() && nums[i] >= nums[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    ans.push_back(nums[q.front()]);
    for (int i = k; i < nums.size(); ++i) {
        while (!q.empty() && nums[i] >= nums[q.back()])
            q.pop_back();
        q.push_back(i);
        while (q.front() <= i - k)
            q.pop_front();
        ans.push_back(nums[q.front()]);
    }
    return ans;
}

class MyCircularDeque
{
public:
    MyCircularDeque(int k)
    {
        capacity = k + 1;
        front = 0;
        rear = 0;
        elements = std::vector<int>(k + 1);
    }

    bool insertFront(int v)
    {
        if (isFull())
            return false;
        front = (front - 1 + capacity) % capacity;
        elements[front] = v;
        return true;
    }

    bool insertLast(int v)
    {
        if (isFull())
            return false;
        elements[rear] = v;
        rear = (rear + 1) % capacity;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;
        front = (front + 1) % capacity;
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;
        rear = (rear - 1 + capacity) % capacity;
        return true;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return elements[front];
    }

    int getLast()
    {
        if (isEmpty())
            return -1;
        return elements[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty() { return rear == front; }

    bool isFull() { return (rear + 1) % capacity == front; }

private:
    std::vector<int> elements;
    int front = 0;
    int rear = 0;
    int capacity;
};

struct DLinkListNode
{
    DLinkListNode(int v)
        : v(v)
        , next(nullptr)
        , prev(nullptr)
    {
    }

    int v;
    DLinkListNode *next;
    DLinkListNode *prev;
};

class MyDeque
{
public:
    MyDeque(int k)
        : head(nullptr)
        , tail(nullptr)
        , capacity(k)
        , size(0)
    {
    }

    bool insertFront(int v)
    {
        if (isFull())
            return false;
        DLinkListNode *node = new DLinkListNode(v);
        if (isEmpty()) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        size++;
        return true;
    }

    bool insertLast(int v)
    {
        if (isFull())
            return false;

        DLinkListNode *node = new DLinkListNode(v);
        if (isEmpty()) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        size++;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;
        DLinkListNode *node = head;
        head = head->next;
        head->prev = nullptr;
        delete node;
        size--;
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;
        DLinkListNode *node = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete node;
        size--;
        return true;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return head->v;
    }

    int getLast()
    {
        if (isEmpty())
            return -1;
        return tail->v;
    }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == capacity; }

private:
    DLinkListNode *head;
    DLinkListNode *tail;
    int capacity;
    int size;
};
