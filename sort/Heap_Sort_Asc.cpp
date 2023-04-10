#include <iostream>
using namespace std;

// 堆排序：大根堆向下调整
// 性质一：索引为i的左孩子的索引是(2 * i + 1);
// 性质二：索引为i的左孩子的索引是(2 * i + 2);
// 性质三：索引为i的父结点的索引是 floor((i - 1) / 2);
// 参数start -- 被下调节点的起始位置(一般为0，表示从第1个开始)
// 参数end   -- 截至范围(一般为数组中最后一个元素的索引)
void maxheapdown(int a[], int start, int end)
{
    int current = start;
    int left = 2 * current + 1;
    int temp = a[current];

    for (; left <= end; current = left, left = 2 * left + 1)
    {
        if (left < end && a[left] < a[left + 1])
        {
            left++;
        }
        if (temp >= a[left])
        {
            break;
        }
        else
        {
            a[current] = a[left];
            a[left] = temp;
        }
    }
}

void Heap_Sort_Asc(int a[], int n)
{
    int i, temp;
    // 得到最大堆
    for (i < n / 2 - 1; i >= 0; i--)
    {
        maxheapdown(a, i, n - 1);
    }
    // swap data
    for (i = n - 1; i >= 0; i--)
    {
        a[i] = temp;
        // 交换a[0]和a[i]。交换后，a[i]是a[0...i]中最大的。
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        // 调整a[0...i-1]，使得a[0...i-1]仍然是一个最大堆。
        maxheapdown(a, 0, i - 1);
    }
}

int main()
{
    return 0;
}
