#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        copy(matrix[0].begin(), matrix[0].end(), dp[0].begin());
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int mn = dp[i - 1][j];
                // 当j > 0 && j < n - 1 连个if都会进
                if (j > 0) // 边界条件，当j = n - 1时候，只能取 dp[i-1][j] dp[i-1][j-1]
                {
                    mn = min(mn, dp[i - 1][j - 1]);
                }
                if (j < n - 1) // 边界条件，当j == 0时候，只能取 dp[i-1][j] dp[i-1][j+1]
                {
                    mn = min(mn, dp[i - 1][j + 1]);
                }
                dp[i][j] = mn + matrix[i][j];
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

int main()
{
    Solution s;
    vector<vector<int>> vec = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    int res = s.minFallingPathSum(vec);
    cout << res;
    return 0;
}