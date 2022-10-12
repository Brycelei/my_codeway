#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int n, a[12000], b[12000];
void merge(int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];
    while (j <= high)
        b[k++] = a[j++];
    for (int i = low; i <= high; i++)
        a[i] = b[i];
}
void mergesort(int x, int y)
{
    if (x >= y)
        return;
    int mid = (x + y) / 2;
    mergesort(x, mid);
    mergesort(mid + 1, y);
    merge(x, mid, y);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    mergesort(1, n); //调用函数
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}