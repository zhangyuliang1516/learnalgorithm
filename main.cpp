#include "utils.h"
#include "sort.h"
#include "myvector.h"
#include "linkedlist.h"

#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    int arr[] = { 8,      200, 90, 7000, 6, 10000, 1500, 120, 14, 130,
                  160000, 10,  5,  3,    8, 2,     9,    7,   6,  10 };
    insertSort2(arr, 20);
    return 0;
}
