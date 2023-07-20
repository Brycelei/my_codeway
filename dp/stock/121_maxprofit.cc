#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
// C++
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        //dp[i][0] 表示第i天持有股票所得最多现金
        //dp[i][0] 表示第i天不持有股票所得最多现金
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i][0] + prices[i]);
        }
        return dp[n - 1][1];
    }
};

int main()
{
    vector<int> prices = {3, 6, 9, 12};
    class Solution A;
    A.maxProfit(prices);
    return 0;
}