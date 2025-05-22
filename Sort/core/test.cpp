#include <Sort/bubbleSort.h>
#include <Sort/heapSort.h>
#include <Sort/insertSort.h>
#include <Sort/qSort.h>
#include <Sort/selectSort.h>
#include <Sort/shellSort.h>
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
        int a[9] = { 8,7,6,5,4,3,2,1,0 };
       heapSort(a, 9);
        for (auto& i : a) {
            std::cout << i << " ";
        }

    // std::vector<int> a { 2, 3, 1, 6, 3, 7, 10, 2, 4 };
    // std::sort(a.rbegin(), a.rend());
    // for (auto& i : a) {
    //     std::cout << i << " ";
    // }
}
