#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int pre = 0, maxSub = nums[0];
        for (auto &x : nums)
        {
            pre = max(x, pre + x);
            maxSub = max(pre, maxSub);
        }
        return maxSub;
    }
    int maxSubArray1(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int res = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> vec = {5, 4, -1, 7, 8};
    s.maxSubArray(vec);
    // cout << res;
    return 0;
}