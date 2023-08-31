/**
 * @file getKthMagicNumber.cpp
 * @author your name (you@domain.com)
 * @brief 有些数的素因子只有 3，5，7，请设计一个算法找出第 k 个数。注意，不是必须有这些素因子，
 * 而是必须不包含其他的素因子。例如，前几个数按顺序应该是 1，3，5，7，9，15，21。
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/get-kth-magic-number-lcci
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * @version 0.1
 * @date 2022-09-28
 *
 * @copyright Copyright (c) 2022
 *
 *
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int getKthMagicNumber(int k)
    {
        vector<int> dp(k + 1);
        dp[1] = 1;
        int p3 = 1, p5 = 1, p7 = 1;
        for (int i = 2; i <= k; i++)
        {
            int num3 = dp[p3] * 3, num5 = dp[p5] * 5, num7 = dp[p7] * 7;
            dp[i] = min(min(num3, num5), num7);
            if (dp[i] == num3)
            {
                p3++;
            }
            if (dp[i] == num5)
            {
                p5++;
            }
            if (dp[i] == num7)
            {
                p7++;
            }
        }
        return dp[k];
    }
};