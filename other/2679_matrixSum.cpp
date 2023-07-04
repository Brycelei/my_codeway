#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <stack>
#include <functional>
using namespace std;

class Solution
{
public:
    int matrixSum(vector<vector<int>> &nums)
    {
        int n = nums.size();
        int m = nums[0].size();
        int res = 0;
        // sort(nums.begin(), nums.end());
        for (int i = n - 1; i >= 0; i--)
        {
            sort(nums[i].begin(), nums[i].end());
        }
        int minres = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            int a = minres;
            for (int j = 0; j < n; j++)
            {
                a = max(a, nums[j][i]);
                if (j == n - 1)
                {
                    res += a;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> vec = {{7, 2, 1}, {6, 4, 2}, {6, 5, 3}, {3, 2, 1}};
    int k = 4;
    int res = s.matrixSum(vec);
    cout << res;
    return 0;
}