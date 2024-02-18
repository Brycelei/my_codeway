#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <string.h>
// #include <stdio.h>
using namespace std;

class Solution
{
public:
    int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price, vector<vector<int>> &trips)
    {
        vector<vector<int>> g(n);
        for (auto &e : edges)
        {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x); // 建树
        }

        vector<int> cnt(n);
        for (auto &t : trips)
        {
            int end = t[1];
            function<bool(int, int)> dfs = [&](int x, int fa) -> bool
            {
                if (x == end)
                {
                    cnt[x]++;
                    return true; // 找到 end
                }
                for (int y : g[x])
                {
                    if (y != fa && dfs(y, x))
                    {
                        cnt[x]++; // x 是 end 的祖先节点，也就在路径上
                        return true;
                    }
                }
                return false; // 未找到 end
            };
            dfs(t[0], -1);
        }

        // 类似 337. 打家劫舍 III
        function<pair<int, int>(int, int)> dfs = [&](int x, int fa) -> pair<int, int>
        {
            int not_halve = price[x] * cnt[x]; // x 不变
            int halve = not_halve / 2;         // x 减半
            for (int y : g[x])
            {
                if (y != fa)
                {
                    auto [nh, h] = dfs(y, x); // 计算 y 不变/减半的最小价值总和
                    not_halve += min(nh, h);  // x 不变，那么 y 可以不变，可以减半，取这两种情况的最小值
                    halve += nh;              // x 减半，那么 y 只能不变
                }
            }
            return {not_halve, halve};
        };
        auto [nh, h] = dfs(0, -1);
        return min(nh, h);
    }
};
/*
贪心

dfs
*/

int main()
{

    int n = 4;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}};
    vector<vector<int>> trips = {{0, 3}, {2, 1}, {2, 3}};
    vector<int> prices = {2, 2, 10, 6};
    int seats = 2;
    Solution s;
    int res = s.minimumTotalPrice(4, edges, prices, trips);
    cout << res << endl;
    return 0;
}