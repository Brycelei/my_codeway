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
class Solution2
{
public:
    int count = 0;
    int sum = 0;
    int minimumPossibleSum(int n, int target)
    {
        if (n == 1)
            return 1;
        vector<bool> iscan(target, 0);
        for (int i = 1; i < (target >> 1); i++)
        {
            iscan[target - i] = true;
        }
        // int c = 0;
        //  for (auto s : iscan)
        //  {
        //      if (s)
        //          c++;
        //  }
        int i = 1;
        for (i = 1; i < iscan.size(); i++)
        {
            if (!iscan[i])
            {
                count++;
                sum += i;
            }
        }
        while (count != n)
        {
            int temp = target;
            sum += target;
            target++;
            count++;
        }
        return sum;
    }
};

int main()
{
    Solution2 a;
    int res = a.minimumPossibleSum(16, 6);
    int temp = 0;
    for (int i = 1; i <= 18; i++)
    {
        temp += i;
    }
    cout << temp;
    return 0;
}
