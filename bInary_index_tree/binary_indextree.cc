#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[1000001];
int c[1000001];
int lowbit(int i)
{
    return i & (-i);
}
void update(int i, int x, int n)
{
    while (i <= n)
    {
        c[i] += x;
        i += lowbit(i);
    }
}
int downdate(int i)
{
    int sum = 0;
    while (i > 0)
    {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(i, a[i], n);
    }
    int x, y, z;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> z;
        if (x == 1)
            update(y, z, n);
        else
            cout << downdate(z) - downdate(y - 1) << endl;
    }
    return 0;
}