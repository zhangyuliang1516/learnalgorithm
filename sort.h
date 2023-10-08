#pragma once

#include <vector>

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void bubbleSort2(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i) {
        bool sorted = true;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                sorted = false;
            }
        }
        if (sorted)
            break;
    }
}

void selectSort(int arr[], int n)
{
    for (int i = 0; i < n; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i) {
            int tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }
}

void insertSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int value = arr[i];
        int j = 0;
        for (j = 0; j < i; ++j) {
            if (arr[j] > value)
                break;
        }
        if (j != i) {
            for (int k = i - 1; k >= j; --k)
                arr[k + 1] = arr[k];
            arr[j] = value;
        }
    }
}

void insertSort2(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int value = arr[i];
        int j = 0;
        for (j = i - 1; j >= 0; --j) {
            if (arr[j] > value) {
                arr[j + 1] = arr[j];
            } else {
                break;
            }
        }
        arr[j + 1] = value;
    }
}

void shellSort(int arr[], int n)
{
    int gap = 1;
    while (gap < n) {
        gap = gap * 3 + 1;
    }
    while (gap > 0) {
        for (int i = gap; i < n; ++i) {
            int tmp = arr[i];
            int j = i - gap;
            while (j >= 0 && arr[j] > tmp) {
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = tmp;
        }
        gap /= 3;
    }
}

void merge(int arr[], int tmpArr[], int start, int mid, int end)
{
    for (int i = start; i <= end; ++i)
        tmpArr[i] = arr[i];
    int left = start;
    int right = mid + 1;
    for (int i = start; i <= end; ++i) {
        if (left > mid)
            arr[i] = tmpArr[right++];
        else if (right > end)
            arr[i] = tmpArr[left++];
        else if (tmpArr[left] < tmpArr[right])
            arr[i] = tmpArr[left++];
        else
            arr[i] = tmpArr[right++];
    }
}

void subMergeSort(int arr[], int tmpArr[], int start, int end)
{
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;
    subMergeSort(arr, tmpArr, start, mid);
    subMergeSort(arr, tmpArr, mid + 1, end);
    merge(arr, tmpArr, start, mid, end);
}

void mergeSort(int arr[], int n)
{
    int *tmpArr = new int[n];
    subMergeSort(arr, tmpArr, 0, n - 1);
}

int partion(int arr[], int start, int end)
{
    int base = arr[start];
    int mark = start;
    for (int i = start + 1; i <= end; ++i) {
        if (arr[i] < base) {
            mark++;
            int tmp = arr[i];
            arr[i] = arr[mark];
            arr[mark] = tmp;
        }
    }
    arr[start] = arr[mark];
    arr[mark] = base;
    return mark;
}

int partionV2(int arr[], int start, int end)
{
    int left = start;
    int right = end;
    int base = arr[start];
    while (true) {
        while (left < right && arr[left] < base)
            left++;
        while (left < right && arr[right] > base)
            right--;
        if (left <= right)
            break;
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
    }
    arr[start] = arr[left];
    arr[left] = base;
    return left;
}

void subQuickSort(int arr[], int start, int end)
{
    if (end <= start)
        return;
    int mid = partion(arr, start, end);
    subQuickSort(arr, start, mid - 1);
    subQuickSort(arr, mid + 1, end);
}

void quickSort(int arr[], int n)
{
    subQuickSort(arr, 0, n - 1);
}

void sink(int arr[], int index, int n)
{
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int present = index;
    if (leftChild < n && arr[leftChild] > arr[present])
        present = leftChild;
    if (rightChild < n && arr[rightChild] > arr[present])
        present = rightChild;
    if (present != index) {
        int tmp = arr[index];
        arr[index] = arr[present];
        arr[present] = tmp;
        sink(arr, present, n);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2; i >= 0; --i)
        sink(arr, i, n);
}

void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i = n - 1; i > 0; --i) {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        n--;
        sink(arr, 0, n);
    }
}

void countSort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max)
            max = arr[i];
    }
    int *countArr = new int[max + 1] { 0 };
    for (int i = 0; i < n; ++i)
        countArr[arr[i]]++;
    int index = 0;
    for (int i = 0; i < max + 1; ++i) {
        while (countArr[i]-- > 0)
            arr[index++] = i;
    }
}

void bucketSort(int arr[], int n)
{
    if (n <= 0)
        return;
    int max = arr[0];
    int min = arr[0];
    for (int i = 0; i < n; ++i) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    int diff = max - min;
    /* int capacity = 1;
    const int bucketCount = 10;
    while (diff) {
        diff /= 10;
        capacity *= 10;
    }
    capacity /= 10;
    std::vector<int> buckets[bucketCount]; */
    int capacity = 100;
    int bucketCount = diff / capacity + 1;
    std::vector<std::vector<int>> buckets;
    buckets.resize(bucketCount);
    for (int i = 0; i < n; ++i) {
        int index = (arr[i] - min) / capacity;
        buckets[index].push_back(arr[i]);
        for (int j = buckets[index].size() - 1; j > 0; --j) {
            if (buckets[index][j] < buckets[index][j - 1])
                std::swap(buckets[index][j], buckets[index][j - 1]);
        }
    }
    int index = 0;
    for (int i = 0; i < bucketCount; ++i) {
        for (int j = 0; j < buckets[i].size(); ++j)
            arr[index++] = buckets[i][j];
    }
}

void radixSort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max)
            max = arr[i];
    }
    int *tmp = new int[n];
    int *count = new int[10];
    int radix = 1;
    while (1) {
        if (max < radix)
            break;

        for (int i = 0; i < 10; ++i)
            count[i] = 0;
        for (int i = 0; i < n; ++i) {
            int index = (arr[i] / radix) % 10;
            count[index]++;
        }
        for (int i = 1; i < 10; ++i)
            count[i] = count[i - 1] + count[i];
        for (int i = n - 1; i >= 0; --i) {
            int index = (arr[i] / radix) % 10;
            tmp[count[index] - 1] = arr[i];
            count[index]--;
        }
        for (int i = 0; i < n; ++i)
            arr[i] = tmp[i];
        radix *= 10;
    }
    delete[] count;
    delete[] tmp;
}
