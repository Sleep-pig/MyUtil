#include <iostream>
#include <utility>
template <typename T>

void max_heap(T a[], int father_index, int len)
{
    int larget_index = father_index;
    int left = father_index * 2 + 1;
    int right = father_index * 2 + 2;

    if (left < len && a[left] > a[larget_index]) {
        larget_index = left;
    }

    if (right < len && a[right] > a[larget_index]) {
        larget_index = right;
    }

    if (larget_index != father_index) {
        std::swap(a[larget_index], a[father_index]);
        max_heap(a, larget_index, len);
    }
}

template <typename T>

void heapSort(T a[], int len)
{
    for (int i = len / 2 - 1; i >= 0; i--) {
        max_heap(a, i, len);
    }

    for (int i = 0; i < len; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    for (int i = len - 1; i > 0; i--) {
        std::swap(a[0], a[i]);
        for (int i = 0; i < len; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
        max_heap(a, 0, i);
    }
}