#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size();
        int total = 0;
        int maxpre = 0;
        int minpre = 0;
        int curmax = nums[0], curmin = nums[0];
        for (auto &x : nums)
        {
            maxpre = max(maxpre + x, x);
            curmax = max(x, maxpre);
            total += x;
            minpre = min(minpre + x, minpre);
            curmin = min(minpre, x);
        }
        return curmax > 0 ? max(total - curmin, curmax) : curmax;
    }
};
int main()
{
    Solution s;
    vector<int> vec = {5, 4, -1, 7, 8};
    s.maxSubarraySumCircular(vec);
    // cout << res;
    return 0;
}