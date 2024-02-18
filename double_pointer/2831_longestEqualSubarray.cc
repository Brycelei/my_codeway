#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int longestEqualSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, vector<int>> umap;
        for (int i = 0; i < n; i++)
            umap[nums[i]].emplace_back(i);
        for (auto &p : umap)
        {
            auto &vec = p.second;
            for (int i = 0, j = 0; i < vec.size(); i++)
            {
                while (j <= i && vec[i] - vec[j] + 1 - (i - j + 1) > k)
                {
                    j++;
                    cout << j << endl;
                }
                ans = max(ans, i - j + 1);
            }
        }
        return ans;
    }
};

/*


1 3 2 3 1 3  k = 3

umap[1] = {0,4}  i是 0到1，
umap[3] = {1,3,5}
umap[2] = {2}
// 子数组删除之前的长度为 vec[i] - vec[j] + 1
// 其中含有元素 nums[vec[i]] 的数量为 i - j + 1
5 - 2

我们枚举等值子数组的右端点 i，用另一个指针 j 计算以 i 为结尾的最长等值子数组的开头。当子数组中不等于 x 的元素数量不超过 k 个时，
这个子数组删除之后就是等值子数组。

1 1 2 2 1 1  k = 2



*/
int main()
{
    Solution s;
    vector<int> vec = {1, 3, 2, 3, 1, 2, 5, 3};
    int res = s.longestEqualSubarray(vec, 3);
    cout << res;
    return 0;
}