#include <iostream>
using namespace std;

// 归并排序：将两个相邻有序区间合并成一个
void merge(int *a, int start, int mid, int end)
{
    int *tmp = new int[end - start + 1]; // tmp是汇总2个有序区的临时区域
    int i = start;                       // 第1个有序区的索引
    int j = mid + 1;                     // 第2个有序区的索引
    int k = 0;                           // 临时区域的索引

    while (i <= mid && j <= end)
    {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while (i <= mid)
        tmp[k++] = a[i++];

    while (j <= end)
        tmp[k++] = a[j++];

    // 将排序后的元素，全部都整合到数组a中。
    for (i = 0; i < k; i++)
        a[start + i] = tmp[i];

    delete[] tmp;
}
// 归并排序：从上到下（递归方式）
void Merge_Sort(int *a, int start, int end)
{
    if (a == NULL || start >= end)
        return;

    int mid = (end + start) / 2;
    Merge_Sort(a, start, mid);   // 递归排序a[start...mid]
    Merge_Sort(a, mid + 1, end); // 递归排序a[mid+1...end]

    // a[start...mid] 和 a[mid...end]是两个有序空间，
    // 将它们排序成一个有序空间a[start...end]
    merge(a, start, mid, end);
}

int main()
{
    int a[] = {1, 2, 3, 4};
    Merge_Sort(a, 0, sizeof(a) / sizeof(int));
    for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        cout << a[i] << "\n";
    }

    return 0;
}