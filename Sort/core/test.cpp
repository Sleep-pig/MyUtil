#include <Sort/bubbleSort.h>
#include <Sort/qSort.h>
#include <Sort/insertSort.h>
#include <Sort/shellSort.h>
#include <Sort/selectSort.h>
#include <Sort/heapSort.h>
#include <iostream>
int main()
{
    int a[9] = { 2, 3, 1, 6, 3, 7, 10, 2, 4 };
   heapSort(a, 9);
    for (auto& i : a) {
        std::cout << i << " ";
    }
}
