#pragma once

#include <iostream>
#include <algorithm>

void testHeap()
{
    int heap[100];
    int size = 0;
    for (int i = 0; i < 10; ++i) {
        int v;
        std::cin >> v;
        heap[size++] = v;
        // std::push_heap(heap, heap + size, std::greater<int>());
        std::push_heap(heap, heap + size);
    }
    int n = size;
    for (int i = 0; i < n; ++i)
        std::cout << heap[i] << " ";
    std::cout << std::endl;

    for (int i = 0; i < n; ++i) {
        // std::pop_heap(heap, heap + size, std::greater<int>());
        std::pop_heap(heap, heap + size);
        int v = heap[--size];
        std::cout << v << " ";
    }
    std::cout << std::endl;
}
