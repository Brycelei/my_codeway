#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int target)
    {
        if (accumulate(nums.begin(), nums.end(), 0LL) < target)
            return -1;
        long long cnt[31]{};
        for (int x : nums)
            cnt[__builtin_ctz(x)]++;
        int ans = 0, i = 0;
        long long s = 0;
        while ((1LL << i) <= target)
        {
            s += cnt[i] << i;
            cout << s << endl;
            int mask = (1LL << ++i) - 1;
            if (s >= (target & mask))
                continue;
            ans++; // 一定要找更大的数操作
            for (; cnt[i] == 0; i++)
                ans++; // 还没找到，继续找更大的数
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 8};
    int x = s.minOperations(nums, 7);
    return 0;
}

/*
0000 0011
0000 1010
0000 0101
0001 1001
0000 0010
0000 1000


0 000 0000 0000 0000 0000 0000 0001 1001
k = 27;

0000 从第k+1位到最高位



*/