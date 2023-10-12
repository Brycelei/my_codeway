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

    为什么要在哈希表中插入{0, -1}，我觉得是这样的，快速计算子数组的和，j到i，所以

    sum(i)-sum(j-1)。当计算的子数组仅为第一个元素时，下标是相等的i==j==0,套用公式

    sum(0)-sum(0-1)，这时，我们就会发现，我们需要一个下标为-1的前缀和。由于map的键为前缀和，

    值为下标。下标我们有了，就是-1，但是它的前缀和是多少呢。由于前缀和就是前面的数字加前来的和，前面没有数字，所以键为0，得{0,-1}。不知道我这么说对不对？
*/

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> ump;
        ump[0] = -1; // 第 i 个元素的前缀和正好是 0 ，从起始元素到第 i 个元素的子数组正好满足条件 (包含起始元素)。
        int preSum = 0;
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            preSum += nums[i] == 0 ? -1 : 1;
            if (ump.count(preSum - 0) != 0)
            {                                              // 注意这里是if else，不像《560. 和为 K 的子数组》每轮循环都更新哈希表，只有没出现过的前缀和才会更新下标
                result = max(result, i - ump[preSum - 0]); // 为什么下标计算时不加1，因为ump[0] = -1;
            }
            else
            {
                ump[preSum] = i; // 从左往右遍历，首次加入的也一定是每个前缀和取值出现的最小下标
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {0, 1, 0};
    s.findMaxLength(vec);
    return 0;
}