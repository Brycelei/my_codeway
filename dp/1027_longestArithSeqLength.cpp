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
    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size(), res = 0;
        vector<vector<int>> f(n, vector<int>(1050, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int d = nums[i] - nums[j] + 501;
                f[i][d] = f[j][d] + 1;
                res = max(res, f[i][d]);
            }
        }
        return res + 1;
    }
};

int main()
{
    vector<int> prices = {3, 6, 9, 12};
    vector<int> popped = {9, 4, 7, 2, 10};
    class Solution A;
    A.longestArithSeqLength(popped);
    return 0;
}