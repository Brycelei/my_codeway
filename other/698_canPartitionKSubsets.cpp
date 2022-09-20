#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <stack>
#include <functional>
using namespace std;
/**
 * @brief 输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
 * 输出： True
 * 说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。
 *  来源：力扣（LeetCode） 链接：https://leetcode.cn/problems/partition-to-k-equal-sum-subsets
 */

/**
 * @brief void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}
 *
 */
class Solution
{
public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % k)
        {
            return false;
        }
        s /= k;
        int n = nums.size();
        vector<int> cur(k);
        function<bool(int)> dfs;
        dfs = [&](int i)
        {
            if (i == n)
            {
                return true;
            }
            for (int j = 0; j < k; ++j)
            {
                if (j && cur[j] == cur[j - 1])
                {
                    continue;
                }
                cur[j] += nums[i];
                // s为平均值
                if (cur[j] <= s && dfs(i + 1))
                {
                    return true;
                }
                cur[j] -= nums[i];
            }
            return false;
        };
        sort(nums.begin(), nums.end(), greater<int>());
        return dfs(0);
    }
};

int main()
{
    Solution s;
    vector<int> vec = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;
    int res = s.canPartitionKSubsets(vec, k);
    return 0;
}