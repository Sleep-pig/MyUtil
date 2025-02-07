#include <utility>
template <typename T>

void selectSort(T a[], int len)
{
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (a[j] < a[i])
                std::swap(a[i], a[j]);
        }
    }
}