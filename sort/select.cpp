#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void select(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minnum = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minnum])
            {
                minnum = j;
            }
        }
        if (minnum != i)
        {
            std::swap(a[i], a[minnum]);
        }
    }
}

// 快速排序（从小到大）
void quickSort(int left, int right, vector<int> &arr)
{
    if (left >= right)
        return;
    int i, j, base, temp;
    i = left, j = right;
    base = arr[left]; // 取最左边的数为基准数
    while (i < j)
    {
        while (arr[j] >= base && i < j)
            j--;
        while (arr[i] <= base && i < j)
            i++;
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // 基准数归位
    arr[left] = arr[i];
    arr[i] = base;
    quickSort(left, i - 1, arr);  // 递归左边
    quickSort(i + 1, right, arr); // 递归右边
}

void bubble_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int main()
{

    vector<int> a = {5, 3, 4, 6};

    // quickSort(0, 3, a);
    bubble_sort(a);
    for (auto &x : a)
    {
        std::cout << x << "\n";
    }

    vector<int> index;
    iota(index.begin(), index.end(), 0);
    return 0;
}
