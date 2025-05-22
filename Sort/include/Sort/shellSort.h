#include <utility>
template <typename T>


void shellSort(T a[], int len)
{
    for (int gap = len / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < len; i++) {
            int j;
            int insert_num = a[i];
            for (j = i; j >= gap && a[j] < a[j - gap]; j -= gap) {
                std::swap(a[j], a[j-gap]);
            }
            a[j] = insert_num;
        }
    }
}