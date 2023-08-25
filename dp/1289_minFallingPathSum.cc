#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> d(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++)
        {
            d[0][i] = grid[0][i];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (j == k)
                    {
                        continue;
                    }
                    d[i][j] = min(d[i][j], d[i - 1][k] + grid[i][j]);
                }
            }
        }
        int res = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            res = min(res, d[n - 1][j]);
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution s;
    int a = s.minFallingPathSum(grid);
    cout << a;
    return 0;
}