#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;
class Solution
{
public:
    int findChampion(vector<vector<int>> &grid)
    {
        int res = -1;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> index(n);
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)
            {

                if (grid[i][j] == 1)
                {
                    g[j].emplace_back(i);
                    index[i]++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (index[i] == 0)
            {
                res = i;
                return res;
            }
        }
        return res;
    }
};
int main()
{
    vector<vector<int>> nums = {{0, 0, 0}, {1, 0, 1}, {1, 0, 0}};
    Solution s;
    int res = s.findChampion(nums);
    cout << res;
    return 0;
}
