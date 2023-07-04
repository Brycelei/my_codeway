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
    int maximumSum(vector<int> &arr)
    {
        int dp0 = arr[0], dp1 = 0, res = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            dp1 = max(dp0, dp1 + arr[i]);
            dp0 = max(dp0, 0) + arr[i];
            res = max(res, max(dp0, dp1));
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> vec = {-1, -1, -1, -1};
    int k = 4;
    int res = s.maximumSum(vec);
    return 0;
}