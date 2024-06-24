#include <iostream>
#include <set>
#include <vector>

using namespace std;

int partion(int *numbers, int start, int end)
{
    int base = numbers[start];
    int mark = start;
    for (int i = start + 1; i <= end; ++i) {
        if (numbers[i] < base) {
            mark++;
            int tmp = numbers[mark];
            numbers[mark] = numbers[i];
            numbers[i] = tmp;
        }
    }
    numbers[start] = numbers[mark];
    numbers[mark] = base;
    return mark;
}
void kLeastNumbers1(int *numbers, int n, int *output, int k)
{
    if (numbers == nullptr || n <= 0 || output == nullptr || k < 0 || k > n)
        return;
    int start = 0;
    int end = n - 1;
    int index = partion(numbers, start, end);
    while (index != k) {
        if (index > k) {
            end = index - 1;
            index = partion(numbers, start, end);
        } else {
            start = index + 1;
            index = partion(numbers, start, end);
        }
    }
    for (int i = 0; i < k; ++i)
        output[i] = numbers[i];
}

typedef multiset<int, std::greater<int>> intSet;
typedef multiset<int, std::greater<int>>::iterator setIterator;
void kLeastNumbers2(const vector<int> &numbers, intSet &leastNumbers, int k)
{
    if (k < 1 || numbers.size() < k)
        return;
    leastNumbers.clear();
    for (auto iter = numbers.begin(); iter != numbers.end(); ++iter) {
        if (leastNumbers.size() < k) {
            leastNumbers.insert(*iter);
        } else {
            setIterator iterGreatest = leastNumbers.begin();
            if (*iter < *iterGreatest) {
                leastNumbers.erase(*iterGreatest);
                leastNumbers.insert(*iter);
            }
        }
    }
}

void sink(int arr[], int n, int index)
{
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int present = index;
    if (left < n && arr[present] < arr[left])
        present = left;
    if (right < n && arr[present] < arr[right])
        present = right;
    if (present != index) {
        int tmp = arr[present];
        arr[present] = arr[index];
        arr[index] = tmp;
        sink(arr, n, present);
    }
}

int main()
{
    int data[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
    int n = sizeof(data) / sizeof(int);
    vector<int> vectorData;
    for (int i = 0; i < n; ++i)
        vectorData.push_back(data[i]);

    intSet leastNumbers;
    kLeastNumbers2(vectorData, leastNumbers, 4);
    for (setIterator iter = leastNumbers.begin(); iter != leastNumbers.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
    return 1;
}
