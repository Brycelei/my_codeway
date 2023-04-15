#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> temp;
    vector<vector<int>> path;
    vector<vector<int>> subsets(vector<int> &nums)
    {
        backtrack(nums, 0);
        return path;
    }
    void backtrack(vector<int> &nums, int cur)
    {
        if (cur == nums.size())
        {
            path.emplace_back(temp);
            return;
        }
        temp.push_back(nums[cur]);
        backtrack(nums, cur + 1);
        temp.pop_back();
        backtrack(nums, cur + 1);
    }
};

int main()
{
    vector<int> vec = {1, 2, 3};
    Solution s;
    vector<vector<int>> res;
    res = s.subsets(vec);
    return 0;
}
