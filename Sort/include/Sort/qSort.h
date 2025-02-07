
#include <utility>
template <typename T>
void qSort(T a[], int l, int r)
{
    if (l >= r)
        return;
    int x = a[l]; // 选一个基底
    int i = l; // 排序范围是 [i+1,j) 因为i==l是基底下标
    int j = r + 1;
    while (i < j) { // 因为j是开区间，所以i!= j
        while (a[++i] < x) // 从左往右找一个比X大的
            break;
        while (a[--j] > x) // 从右往左找一个比X小的
            break;
        if (i > j) // 小的在左边就不用交换了
            break;
        std::swap(a[i], a[j]);
    }
    std::swap(a[l], a[j]); // i j都行 因为i==j
    qSort(a, l, i);
    qSort(a, i, r);
}