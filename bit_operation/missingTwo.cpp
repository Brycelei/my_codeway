#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> missingTwo(vector<int> &nums)
    {
        int xorsum = 0;
        int n = nums.size() + 2;
        for (int num : nums)
        {
            xorsum ^= num;
        }
        for (int i = 1; i <= n; i++)
        {
            xorsum ^= i;
        }
        // 防止溢出
        int lsb = (xorsum == INT_MIN ? xorsum : xorsum & (-xorsum));
        int type1 = 0, type2 = 0;
        for (int num : nums)
        {
            if (num & lsb)
            {
                type1 ^= num;
            }
            else
            {
                type2 ^= num;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (i & lsb)
            {
                type1 ^= i;
            }
            else
            {
                type2 ^= i;
            }
        }
        return {type1, type2};
    }
};

int main()
{
    vector<int> vec = {2, 3};
    Solution s;
    vector<int> res = s.missingTwo(vec);
    for (auto &x : res)
    {
        cout << x << "\n";
    }
    return 0;
}