#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

int binarySearch(int arr[], int n, int target)
{
    int start = 0;
    int end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}
int binarySearch2(int arr[], int l, int r, int target)
{
    if (l > r)
        return -1;
    int mid = l + (r - l) / 2;
    if (arr[mid] == target)
        return mid;
    if (arr[mid] > target)
        return binarySearch2(arr, l, mid - 1, target);
    else
        return binarySearch2(arr, mid + 1, r, target);
}
double pow(double x, int n)
{
    double r = 1.0;
    for (int i = 0; i < n; ++i)
        r *= x;
    return r;
}
double pow2(double x, int n)
{
    if (n == 0)
        return 1.0;
    double t = pow2(x, n / 2);
    if (n % 2)
        return x * t * t;
    return t * t;
}
template <typename T>
class Vector
{
public:
    Vector() {
        data = new T[10];
        size = 0;
        capacity = 10;
    }
    void push_back(T t) {
        if (size == capacity)
            resize(2 * capacity);
        data[size++] = t;
    }
    T pop_back() {
        size--;
        return data[size];
    }
private:
    void resize(int newCapacity) {
        T *newData = new T[newCapacity];
        for (int i = 0; i < size; ++i)
            newData[i] = data[i];
        data = newData;
        capacity = newCapacity;
    }

    T *data;
    int size;
    int capacity;
};

void reverse(std::string &s)
{
    int n = s.size();
    for (int i = 0; i < n / 2; ++i)
        std::swap(s[i], s[n - 1 - i]);
}

std::string intToString(int num)
{
    std::string s = "";
    while (num) {
        s += '0' + num % 10;
        num /= 10;
    }
    reverse(s);
    return s;
}

namespace sort {
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
    for (int i = 0; i <= end; ++i) {
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
} // namespace sort

namespace sort2 {
void bubbleSort(int arr[], int n)
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
            for (int k = i - 1; k >= j; ++k)
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
            if (arr[j] > value)
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = value;
    }
}
void shellSort(int arr[], int n)
{
    int gap = 1;
    while (gap < n)
        gap = gap * 3 + 1;
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
    if (end >= start)
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
    int base = arr[start];
    int left = start;
    int right = end;
    while (1) {
        while (left < right && arr[left] < base)
            left++;
        while (right > left && arr[right] > base)
            right--;
        if (left >= right)
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
    subQuickSort(arr, start, mid);
    subQuickSort(arr, mid + 1, end);
}
void quickSort(int arr[], int n)
{
    subQuickSort(arr, 0, n - 1);
}
void sink(int arr[], int index, int n)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int present = index;
    if (left < n && arr[left] > arr[present])
        present = left;
    if (right < n && arr[right] > arr[present])
        present = right;
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
    for (int i = n - 1; i >= 0; --i) {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        n--;
        sink(arr, 0, n);
    }
}
} // namespace sort2

struct ListNode
{
    ListNode() {}
    ListNode(int x)
    {
        data = x;
        next = nullptr;
    }
    ListNode(int x, ListNode *next)
        :data(x)
        , next(next)
    {}
    int data;
    ListNode *next;
};
ListNode *reverseList2(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr) {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *cur = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return cur;
}
// 1, (2, 3, 4, 5), 6, 7
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *pre = dummy;
    for (int i = 0; i < left - 1; ++i)
        pre = pre->next;
    ListNode *rightNode = pre;
    for (int i = 0; i < right - left + 1; ++i)
        rightNode = rightNode->next;
    ListNode *leftNode = pre->next;
    ListNode *curr = rightNode->next;
    pre->next = nullptr;
    rightNode->next = nullptr;
    reverseList(leftNode);
    pre->next = rightNode;
    leftNode->next = curr;
    return dummy->next;
}
ListNode *reverseBetween2(ListNode *head, int left, int right)
{
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *pre = dummy;
    for (int i = 0; i < left  -1; ++i)
        pre = pre->next;
    ListNode *curr = pre->next;
    ListNode *next;
    for (int i = 0; i < right - left; ++i) {
        next = curr->next;
        curr->next = next->next;
        next->next = pre->next;
        pre->next = next;
    }
    return dummy->next;
}
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB)
{
    std::unordered_set<ListNode *> visited;
    ListNode *temp = headA;
    while (temp) {
        visited.insert(temp);
        temp = temp->next;
    }
    temp = headB;
    while (temp) {
        if (visited.count(temp))
            return temp;
        temp = temp->next;
    }
    return nullptr;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL || headB == NULL)
        return NULL;
    ListNode *pointA = headA;
    ListNode *pointB = headB;
    while (pointA != pointB) {
        if (pointA == NULL)
            pointA = headB;
        else
            pointA = pointA->next;
        if (pointB == NULL)
            pointB = headA;
        else
            pointB = pointB->next;
    }
    return pointA;
}
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr) {
        return l2;
    } else if (l2 == nullptr) {
        return l1;
    } else if (l1->data < l2->data) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}
ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2)
{
    ListNode *preHead = new ListNode(-1);
    ListNode *prev = preHead;
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->data < l2->data) {
            prev->next = l1;
            l1 = l1->next;
        } else {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }
    if (l1 == nullptr)
        prev->next = l2;
    else
        prev->next = l1;
    return preHead->next;
}
ListNode *partionList(ListNode *head, int x)
{
    ListNode *small = new ListNode(0);
    ListNode *smallHead = small;
    ListNode *large = new ListNode(0);
    ListNode *largeHead = large;
    while (head) {
        if (head->data < x) {
            small->next = head;
            small = small->next;
        } else {
            large->next = head;
            large = large->next;
        }
        head = head->next;
    }
    large->next = nullptr;
    small->next = largeHead->next;
    return smallHead->next;
}
ListNode *detectCycle(ListNode *head)
{
    std::unordered_set<ListNode *> visited;
    while (head) {
        if (visited.count(head))
            return head;
        visited.insert(head);
        head = head->next;
    }
    return nullptr;
}
ListNode *detectCycle2(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast) {
        slow = slow->next;
        if (fast->next) {
            fast = fast->next->next;
        } else {
            return nullptr;
        }
        if (fast == slow) {
            ListNode *ptr = head;
            while (ptr != slow) {
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr;
        }
    }
    return nullptr;
}

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    int arr[] = { 8,      200, 90, 7000, 6, 10000, 1500, 120, 14, 130,
                  160000, 10,  5,  3,    8, 2,     9,    7,   6,  10 };
    sort::insertSort2(arr, 20);
    return 0;
}
