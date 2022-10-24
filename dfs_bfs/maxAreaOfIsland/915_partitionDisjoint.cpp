#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int partitionDisjoint(vector<int> &nums)
    {
        int n = nums.size();
        int leftMax = nums[0], leftPos = 0, curMax = nums[0];
        for (int i = 1; i < n - 1; i++)
        {
            curMax = max(curMax, nums[i]);
            if (nums[i] < leftMax)
            {
                leftMax = curMax;
                leftPos = i;
            }
        }
        return leftPos + 1;
    }
};

int main()
{
    vector<int> vec = {5, 0, 3, 8, 6};
    Solution s;
    int res = s.partitionDisjoint(vec);
    cout << res;
    return 0;
}