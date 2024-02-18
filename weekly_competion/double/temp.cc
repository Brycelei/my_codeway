#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <functional>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    vector<int> smallestMissingValueSubtree(vector<int> &parents, vector<int> &nums)
    {
        int n = parents.size();
        vector<vector<int>> g(n);
        vector<int> val(n);
        val[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            g[parents[i]].emplace_back(i);
            val[i] = nums[i];
        }
        vector<int> path;
        vector<int> isvis(n, 0);
        unordered_set<int> uset;
        function<void(int)> dfs = [&](int x)
        {
            if (isvis[x])
            {
                return;
            }
            isvis[x] = 1;

            uset.insert(nums[x]);
            for (int i = 0; i < g[x].size(); i++)
            {
                dfs(g[x][i]);
            }
        };
        vector<int> res(n, 1);
        int iNode = 1, node = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                node = i;
                break;
            }
        }
        while (node != -1)
        {
            dfs(node);
            while (uset.count(iNode))
            {
                iNode++;
            }
            res[node] = iNode;
            node = parents[node];
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> parents = {-1, 0, 0, 2};
    vector<int> nums = {1, 2, 3, 4};

    vector<int> parents1 = {-1, 0, 1, 0, 3, 3};
    vector<int> nums1 = {5, 4, 6, 2, 1, 3};
    vector<int> res = s.smallestMissingValueSubtree(parents1, nums1);
}
