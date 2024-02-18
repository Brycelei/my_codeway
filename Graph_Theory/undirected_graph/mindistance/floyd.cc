#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int m, n, d[301][301];
int main()
{
    memset(d, 0x3f, sizeof(d)); // 这里不能赋值为127，否则之后的加法会爆
    for (int i = 1; i <= n; i++)
        d[i][i] = 0; // 自己到自己的距离为0
    cin >> n >> m;   // n为点数，m为边数
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; // u,v,w分别为起点、终点、权值
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w); // 处理重边
        d[v][u] = min(d[v][u], w); // 无向图的双向性
    }
    for (int k = 1; k <= n; k++) // 一定要先枚举中转点
    {
        for (int i = 1; i <= n; i++) // 枚举起点
        {
            for (int j = 1; j <= n; j++) // 枚举终点
            {
                // 核心代码
                if (d[i][k] + d[k][j] < d[i][j]) // 如果经过中转点可以使直接从i到j的路费减少
                {
                    d[i][j] = d[i][k] + d[k][j]; // 松弛操作
                }
            }
        }
    }
    cout << endl; // 美观

    // 输出
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (d[i][j] != 1061109567) // 如果有路径
                cout << i << '-' << j << ':' << d[i][j] << endl;
        }
    }
    return 0;
}