#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        unordered_set<int> s; // 用于检测元素否被访问过
        int n = nums.size(), ans = 0, sum = 0;
        for (int l = 0, r = 0; r < n; r++)
        {
            while (s.count(nums[r]))
            { // 窗口收缩
                sum -= nums[l];
                s.erase(nums[l++]); // 设置成未访问
            }
            s.insert(nums[r]); // 设置已访问
            sum += nums[r];
            ans = max(ans, sum);
        }
        return ans;
    }
};

/*
4 2 4 5 6

不同的元素的子数组
什么时候缩小窗口呢？
[5,2,1,2,5,2,1,2,5]

5 2 1   2






*/

/*
1 1 0 1


0 1 1 1 0 1 1 0 1

这个数组中就只包含一个 0

*/
int main()
{
    vector<int> vec = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    vector<int> vec1 = {4, 2, 4, 5, 6};

    Solution s;
    int res = s.maximumUniqueSubarray(vec1);
    cout << res;

    return 0;
}