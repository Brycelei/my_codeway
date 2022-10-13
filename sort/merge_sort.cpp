#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int n, a[12000], b[12000];
void merge(int low, int mid, int high)
{
    // low 和 mid 分别是要合并的第一个数列的开头和结尾，mid+1 和 high 分别是第二个数列的开头和结尾
    int i = low, j = mid + 1, k = low;

    // i、j 分别标记第一和第二个数列的当前位置，k 是标记当前要放到整体的哪一个位置
    while (i <= mid && j <= high) //如果两个数列的数都没放完，循环
    {
        //将a[i] 和 a[j] 中小的那个放入 b[k]，然后将相应的标记变量增加
        //将a[i] 和 a[j] 中小的那个放入 b[k]，然后将相应的标记变量增加
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];
    while (j <= high)
        //当有一个数列放完了，就将另一个数列剩下的数按顺序放好
        b[k++] = a[j++];
    //将 b 数组里的东西放入 a 数组，因为 b 数组还可能要继续使用
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