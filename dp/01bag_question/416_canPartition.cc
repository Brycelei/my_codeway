#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum & 1) == 1)
            return false;
        int target = sum >> 1;
        int len = nums.size();
        vector<vector<bool>> dp(len, vector<bool>(target + 1));
        if (nums[0] <= target)
            dp[0][nums[0]] = true;
        for (int i = 1; i < len; i++)
        {
            for (int j = 1; j <= target; j++)
            {
                if (nums[i] <= j)
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[len - 1][target];
    }
};

int main()
{
    Solution s;
    vector<int> vec = {1, 5, 11, 5};
    s.canPartition(vec);
    return 0;
}

// dp[i][j]表示从数组的 [0, i] 这个子区间内挑选一些正整数，每个数只能用一次，使得这些数的和恰好等于 j。
