#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;
class Solution
{
public:
    vector<int> path;
    vector<vector<int>> res;
    int sum = 0;
    int countSubMultisets(vector<int> &nums, int l, int r)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // vector<bool> isused(n, false);
        //  dfs(nums, 0, 6, isused);

        for (int i = l; i <= r; i++)
        {
            vector<bool> isused(n, false);
            dfs(nums, 0, i, isused);
        }
        for (auto &x : res)
        {
            for (auto &y : x)
            {
                cout << y << endl;
            }
        }
        return res.size();
    }
    void dfs(vector<int> &nums, int start, int l, vector<bool> &isused)
    {
        // int sum = 0;
        if (sum == l)
        {
            res.emplace_back(path);
            return;
        }

        for (int i = start; i < nums.size() && sum + nums[i] <= l; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1] && isused[i - 1] == false)
            {
                continue;
            }
            sum += nums[i];
            isused[i] = true;
            path.emplace_back(nums[i]);
            dfs(nums, start + 1, l, isused);
            isused[i] = false;
            sum -= nums[i];
            path.pop_back();
        }
    }
};

int main()
{
    return 0;
}
