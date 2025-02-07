
template <typename T>
void insertSort(T a[], int len)
{
    for (int i = 1; i < len; i++) {
        int insert_num = a[i];
        int is_insert = 0;
        for (int j = i - 1; j >= 0; j--) { //可以使用二分查找找到需要插入的地方
            if (a[j] > insert_num) {
                a[j + 1] = a[j];
                continue;
            }
            if (a[j] <= insert_num) {
                is_insert = 1;
                if (j == i - 1)
                    break;
                a[j + 1] = insert_num;
                break;
            }
        }
        if (!is_insert) {
            a[0] = insert_num;
        }
    }
}