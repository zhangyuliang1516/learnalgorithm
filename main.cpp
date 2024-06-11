#include "utils.h"
#include "sort.h"
#include "myvector.h"
#include "linkedlist.h"
#include "myheap.h"
#include "myqueue.h"
#include "mystack.h"
#include <stack>

#include <iostream>

using namespace std;

namespace test {

}

int main()
{
    int arr[] = { 9, 8, 7, 6, 5, 10, 4, 3, 2, 1 };
    quickSort(arr, 10);
    //    cout << "Hello World!" << endl;
    std::vector<int> temperatures = { 73, 74, 75, 71, 69, 72, 76, 73 };
    std::vector<int> ans = dailyTemperatures(temperatures);
    return 0;
}
