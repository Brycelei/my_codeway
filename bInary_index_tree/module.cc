#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class BIT
{
private:
    vector<int> tree;
    int n;

public:
    // 初始化树状数组的大小
    BIT(int m) : n(m), tree(m + 1) {}
    // 使数组呈现2、4、8、16这种树状
    int lowbit(int x)
    {
        return x & (-x);
    }
    // 查询序列1到x的前缀和
    int query(int x)
    {
        int res = 0;
        while (x)
        {
            res += tree[x];
            x -= lowbit(x);
        }
        return res;
    }
    // 序列x位置的数加1
    void update(int x)
    {
        while (x <= n)
        {
            tree[x]++;
            x += lowbit(x);
        }
    }
};

int main()
{
    int n = 8;
    BIT bit(n);
    vector<int> data = {1, 2, 3, 4, 5, 6, 7, 0};
    vector<int> temp(data);
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n; i++)
    {
        data[i] = lower_bound(temp.begin(), temp.end(), data[i]) - temp.begin() + 1;
    }
    vector<int> data1 = {2, 3, 4, 5, 6, 7, 8, 1};
    vector<int> res;
    // 树状数组维护小于等于当前元素的个数
    int ans = 0;
    int b = 0;
    for (int i = 0; i < n; i++)
    {
        bit.update(data1[i]);
        int a = bit.query(data1[i]);
        res.emplace_back(a);
        b = bit.query(8);
        ans = (ans + bit.query(n) - bit.query(data[i]));
    }
    return 0;
}