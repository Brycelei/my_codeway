#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <stack>
#include <functional>
#include <unordered_map>
using namespace std;
/*
    求 pre[j] - pre[i-1] = k 的区间个数
    pre[j] - k = pre[i-1]
    相似题目：
    560. 和为 K 的子数组
    974. 和可被 K 整除的子数组
    523. 连续的子数组和
    525. 连续数组
第四题
*/

/*
    此方法会超时，因为复杂度为n

*/
class Solution1
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> hash;
        hash[0] = 1;
        int n = nums.size();
        vector<int> presum(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            presum[i + 1] = presum[i] + nums[i];
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = i + 1; j < n + 1; j++)
            {
                if (j - i >= 1 && (presum[j] - presum[i - 1]) % k == 0)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution
{
public:
    // 转换为求sum=0的情况
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (k != 0)
                sum %= k;
            if (mp.find(sum) != mp.end())
            {
                if (i - mp[sum] > 1)
                    return true;
            }
            else
            {
                mp[sum] = i;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {23, 2, 4, 6, 7};
    int k = 6;
    s.checkSubarraySum(vec, k);
    return 0;
}