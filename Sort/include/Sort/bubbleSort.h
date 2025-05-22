#include <utility>
template <typename T>

void bubble_sort(T a[], int len)
{
    for (int i = 0; i < len - 1; i++) { // 只需要排len-1个就能有序
        for (int j = 0; j < len - 1 - i; j++) { // 对于第j个来说他需要比对len-1-i个
            if (a[j] > a[j + 1])
                std::swap(a[j], a[j + 1]);
        }
    }
}
