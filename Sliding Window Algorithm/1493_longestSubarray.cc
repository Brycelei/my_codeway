#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int res = 0;
        int n = nums.size();
        int left = 0, right = 0;
        int count0 = 0;

        while (right < n && left <= right)
        {
            if (nums[right] == 0)
            {
                count0++;
            }
            right++;
            if (count0 > 1)
            {
                if (nums[left] == 0)
                {
                    count0--;
                }
                left++;
            }
        }
        return right - left - 1;
    }
};

/*
1 1 0 1


0 1 1 1 0 1 1 0 1

这个数组中就只包含一个 0

*/
int main()
{
    vector<int> vec = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    vector<int> vec1 = {1, 1, 0, 1};

    Solution s;
    int res = s.longestSubarray(vec1);
    cout << res;

    return 0;
}