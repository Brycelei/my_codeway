#include <iostream>
#include <vector>
using namespace std;

const int maxn = 5e5 + 5;
vector<int> g[maxn];
int p[maxn], dep[maxn];
void dfs(int u, int d)
{
    dep[u] = d;
    int sz = g[u].size();
    for (int i = 0; i < sz; i++)
    {
        int v = g[u][i];
        if (v == p[u])
            continue;
        p[v] = u;
        dfs(v, d + 1);
    }
}
int lca(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);
    while (dep[x] > dep[y])
    {
        x = p[x];
    }
    while (x != y)
    {
        x = p[x];
        y = p[y];
    }
    return x;
}
int main()
{
    int n, m, s;
    int a, b;
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i < n; i++)
    {
        scanf("%d %d", &a, b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs(s, 0);
    while (m--)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}