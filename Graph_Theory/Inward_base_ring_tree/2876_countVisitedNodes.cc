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
    vector<int> countVisitedNodes(vector<int> &edges)
    {
        int n = edges.size();
        vector<vector<int>> rg(n);
        vector<int> degree(n);
        for (int i = 0; i < n; i++)
        {
            int a = edges[i];
            rg[a].emplace_back(i);
            degree[a]++;
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
            int x = que.front();
            que.pop();
            int y = edges[x];
            if (--degree[y] == 0)
            {
                que.push(y);
            }
        }
        vector<int> ans(n, 0);
        function<void(int, int)> rdfs = [&](int x, int depth)
        {
            ans[x] = depth;
            for (int y : rg[x])
            {
                if (degree[y] == 0)
                {
                    rdfs(y, depth + 1);
                }
            }
        };
        for (int i = 0; i < n; i++)
        {
            if (degree[i] <= 0)
            {
                continue;
            }
            // degree[i] = -1;
            vector<int> ring;
            for (int x = i;; x = edges[x])
            {
                degree[x] = -1;
                ring.emplace_back(x);
                if (edges[x] == i)
                {
                    break;
                }
            }
            for (auto x : ring)
            {
                rdfs(x, ring.size());
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> fronts = {1, 2, 0, 0};
    vector<int> res = s.countVisitedNodes(fronts);
    // cout << res;
    return 0;
}