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
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> hash;
        hash[0] = 1;
        int pre = 0;
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            pre += nums[i];
            if (hash.find(pre - k) != hash.end())
                sum += hash[pre - k];
            hash[pre]++;
        }
        return sum;
    }
};
int main()
{
    Solution s;
    vector<int> vec = {1, 2, 3};
    int k = 3;
    int res = s.subarraySum(vec, k);
    return 0;
}