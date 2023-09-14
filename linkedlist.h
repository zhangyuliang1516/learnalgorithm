#pragma once

#include <iostream>
#include <unordered_set>
#include <unordered_map>

struct ListNode
{
    ListNode() { }
    ListNode(int x)
    {
        data = x;
        next = nullptr;
    }
    ListNode(int x, ListNode *next)
        : data(x)
        , next(next)
    {
    }
    int data;
    ListNode *next;
    ListNode *random;
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
    for (int i = 0; i < left - 1; ++i)
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

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *pre = dummy;
    while (pre) {
        ListNode *right = pre;
        for (int i = 0; i < k; ++i) {
            right = right->next;
            if (!right)
                return dummy->next;
        }
        ListNode *left = pre->next;
        ListNode *next = right->next;
        pre->next = nullptr;
        right->next = nullptr;
        reverseList(left);
        pre->next = right;
        left->next = next;
        pre = left;
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

std::unordered_map<ListNode *, ListNode *> cachedNodes;
ListNode *copyRandomNode(ListNode *head)
{
    if (head == nullptr)
        return nullptr;
    if (!cachedNodes.count(head)) {
        ListNode *newHead = new ListNode(head->data);
        cachedNodes[head] = newHead;
        newHead->next = copyRandomNode(head->next);
        newHead->random = copyRandomNode(head->random);
    }
    return cachedNodes[head];
}

ListNode *copyRandomNode2(ListNode *head)
{
    if (head == nullptr)
        return head;
    for (ListNode *node = head; node != nullptr; node = node->next->next) {
        ListNode *newNode = new ListNode(node->data);
        newNode->next = node->next;
        node->next = newNode;
    }
    for (ListNode *node = head; node != nullptr; node = node->next->next) {
        ListNode *next = node->next;
        next->random = node->random ? node->random->random : nullptr;
    }
    ListNode *newHead = head->next;
    for (ListNode *node = head; node != nullptr; node = node->next) {
        ListNode *newNode = node->next;
        node->next = newNode->next;
        newNode->next = newNode->next ? newNode->next->next : nullptr;
    }
    return newHead;
}

ListNode *removeElements(ListNode *head, int v)
{
    if (head == nullptr)
        return nullptr;
    head->next = removeElements(head->next, v);
    return head->data == v ? head->next : head;
}

ListNode *removeElements2(ListNode *head, int v)
{
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *temp = dummy;
    while (temp->next) {
        if (temp->next->data == v)
            temp->next = temp->next->next;
        else
            temp = temp->next;
    }
    return dummy->next;
}
