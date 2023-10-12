#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
class Solution
{
public:
    int maximumInvitations(vector<int> &favorite)
    {
        int n = favorite.size();
        vector<vector<int>> rg(n);
        vector<int> degree(n);
        for (int i = 0; i < n; i++)
        {
            int w = favorite[i];
            rg[w].emplace_back(i);
            degree[w]++;
        }
        queue<int> que;
        for (int i = 0; i < n; i++)
        {
            if (degree[i] == 0)
            {
                que.emplace(i);
            }
        }
        while (!que.empty())
        {
            int v = que.front();
            que.pop();
            int w = favorite[v];
            if (--degree[w] == 0)
            {
                que.push(w);
            }
        }

        function<int(int)> rdfs = [&](int v) -> int
        {
            int max_depth = 1;
            for (int w : rg[v])
            {
                if (degree[w] == 0) // 确保是在树枝上
                {
                    max_depth = max(max_depth, rdfs(w) + 1);
                }
            }
            return max_depth;
        };
        int max_ring_size = 0, sum_chain_size = 0;
        for (int i = 0; i < n; i++)
        {
            if (degree[i] <= 0) // 树枝上的点
            {
                continue;
            }
            //
            degree[i] = -1;
            int ring_size = 1;
            for (int v = favorite[i]; v != i; v = favorite[v])
            {
                degree[v] = -1;
                ++ring_size;
            }
            if (ring_size == 2)
                sum_chain_size += rdfs(i) + rdfs(favorite[i]); // 特殊判断
            else
                max_ring_size = max(max_ring_size, ring_size);
        }
        return max(max_ring_size, sum_chain_size);
    }
};

int main()
{
    Solution s;
    vector<int> fronts = {2, 2, 1, 2};
    int res = s.maximumInvitations(fronts);
    cout << res;
    return 0;
}