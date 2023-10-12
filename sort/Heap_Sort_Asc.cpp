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
    int parent = start;
    int child = start * 2 + 1;
    while (child < end)
    {
        if (child + 1 < end && a[child] < a[child + 1])
        {
            child++;
        }
        if (a[parent] > a[child])
        {
            return;
        }
        else
        {
            swap(a[child], a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
    }
}

void Heap_Sort_Asc(int a[], int n)
{
    int i, temp;
    // 初始化堆：倒数一半开始, 因为后面的在最底层不用调整
    // 创建大顶堆，必须从下往上比较，否则有的不符合大顶堆定义
    for (i < n / 2 - 1; i >= 0; i--)
    {
        maxheapdown(a, i, n - 1);
    }
    // swap data
    for (i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        maxheapdown(a, 0, i);
    }
}

int main()
{
    int arr[] = {4, 3, 5, 2, 1};
    Heap_Sort_Asc(arr, 5);
    return 0;
}
