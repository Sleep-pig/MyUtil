# 排序算法笔记

## 目录
1. [冒泡排序](#冒泡排序)
2. [选择排序](#选择排序)
3. [插入排序](#插入排序)
4. [快速排序](#快速排序)
5. [归并排序](#归并排序)

## 冒泡排序
冒泡排序是一种简单的排序算法。它重复地遍历要排序的数列，一次比较相邻的两个元素，如果它们的顺序错误就把它们交换过来。遍历数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成。

##### 注意事项
```cpp
 for (int i = 0; i < len - 1; i++) { // 只需要排len-1个就能有序
        for (int j = 0; j < len - 1 - i; j++) { // 对于第j个来说他需要比对len-1-i个  
```
##### 复杂度
最优时：即数组已经有序，只需要遍历一次，O(N)
最坏时：O(N^2)

## 选择排序
选择排序是一种简单直观的排序算法。它的工作原理是每一次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的起始位置，直到全部待排序的数据元素排完。

##### 注意事项
```cpp
 for (int i = 0; i < len - 1; i++) { //同理只需要排序len -1个就能有序
        for (int j = i + 1; j < len; j++) { //现在要排的是第i个，那么就从[i+1,len-1]中选一个最小的放在i位置上
```

##### 复杂度
最优时：即数组已经有序，只需要遍历一次，O(N)
最坏时：O(N^2)

## 插入排序
把数组分为已排序和未排序两个部分，流程为从未排序中取出一个作为key，然后在已排序的部分从后往前对比，大于key的则往后面挪位置（key所在的位置可以用），小于则将在其后面插入key值

##### 代码示例
```cpp
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) { //腾位置
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
```

##### 复杂度
最优时：即数组已经有序，只需要遍历一次，O(N)
最坏时：O(N^2)




## 快速排序
快速排序是对冒泡排序的一种改进。它的基本思想是取出一个基准，小于基准的放在其左边，反之在右边。

##### 代码示例
```cpp
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
    std::swap(a[l], a[j]); //交换基准和最后j位置的数（j位置上的数一定小于基准）
    qSort(a, l, i);
    qSort(a, i, r);
}
```

## 归并排序
归并排序是建立在归并操作上的一种有效的排序算法。该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。

### 代码示例
```cpp
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
```