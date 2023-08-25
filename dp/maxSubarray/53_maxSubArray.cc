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
        for (int i = 1; i < n; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(res, dp[i]);
        }
        /*
        空间优化：
        由于只用到dp[i] 和 nums[i] 则用变量替换
        dp[i] = pre;
        pre = max()
        */
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> vec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    s.maxSubArray(vec);
    // cout << res;
    return 0;
}
