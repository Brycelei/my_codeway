#include <iostream>
#include <vector>
typedef int hip;
#include <set>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
long long a[N]; // 存放第i个输入的数字
struct node
{
    int l;          // 当前节点的左端点
    int r;          // 当前节点的右端点
    long long sum;  //[l, r]的和
    long long lazy; // lazy 标记
} tree[4 * N];

// 建立二叉树
void build_tree(int rt, int l, int r)
{
    if (l == r)
    {
        tree[rt].l = l;
        tree[rt].r = r;
        tree[rt].lazy = 0;
        tree[rt].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build_tree(rt * 2, l, mid);
    build_tree(rt * 2 + 1, mid, r);
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].lazy = 0;
    tree[rt].sum = tree[rt * 2].sum + tree[rt * 2 + 1].sum;
}

// 表示rt这个节点该还债了
void pushdown(int rt)
{
    if (tree[rt].lazy)
    {
        tree[rt * 2].sum += (tree[rt * 2].r - tree[rt * 2].l + 1) * tree[rt].lazy;
        tree[rt * 2 + 1].sum += (tree[rt * 2 + 1].r - tree[rt * 2 + 1].l + 1) * tree[rt].lazy;
        tree[rt * 2].lazy += tree[rt].lazy;
        tree[rt * 2 + 1].lazy += tree[rt].lazy;
        tree[rt].lazy = 0;
    }
}
// rt这个节点领到个任务，将[l,r]区间的节点都加k
void update(int rt, int l, int r, long long k)
{
    if (l == tree[rt].l && tree[rt].r == r) // 完全属于自己管辖的范围
    {
        tree[rt].sum += (r - l + 1) * k;
        // 记账
        tree[rt].lazy += k;
        return;
    }
    pushdown(rt);
    // 不完全属于自己的管辖范围，则需要将任务进行拆分
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    // 完全位于左儿子管辖范围
    if (r <= mid)
    {
        update(rt * 2, l, r, k);
    }
    // 完全位于右儿子管辖范围
    else if (l > mid)
    {
        update(rt * 2 + 1, l, r, k);
    }
    else
    {
        update(rt * 2, l, mid, k);
        update(rt * 2 + 1, mid + 1, r, k);
    }
    tree[rt].sum = tree[rt * 2].sum + tree[rt * 2 + 1].sum;
}

long long query(int rt, int l, int r)
{
    if (tree[rt].l == l && tree[rt].r == r)
    {
        return tree[rt].sum;
    }
    // 要往下开始查账了，则把账都还回去
    pushdown(rt);
    long long res = 0;
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    // 完全位于左儿子管辖范围
    if (r <= mid)
    {
        res += query(rt * 2, l, r);
    }
    // 完全位于右儿子管辖范围
    else if (l > mid)
    {
        res += query(rt * 2 + 1, l, r);
    }
    else
    {
        res += query(rt * 2, l, mid);
        res += query(rt * 2 + 1, mid + 1, r);
    }
    return res;
}

int main()
{
    int n, m; // n  个数字， m次操作
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build_tree(1, 1, n); // 根节点是1，所管辖范围是[1,n]
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1) // 更新操作
        {
            int x, y;
            long long k;
            cin >> x >> y >> k; // 将[x,y]区间节点都加k
            update(1, x, y, k);
        }
        else if (op == 2) // 查询操作
        {
            int x, y;
            cin >> x >> y;
            cout << query(1, x, y) << endl;
        }
    }
    return 0;
}