#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static constexpr int HIGH_BIT = 30;
    int findMaximumXOR(vector<int> &nums)
    {
        int x = 0;
        for (int k = HIGH_BIT; k >= 0; k--)
        {
            unordered_set<int> seen;
            for (auto &a : nums)
            {
                seen.insert(a >> k);
            }

            int x_next = x * 2 + 1;
            cout << x_next << endl;
            bool isfound = false;
            for (auto &b : nums)
            {
                if (seen.count(x_next ^ (b >> k)))
                {
                    isfound = true;
                    break;
                }
            }
            if (isfound)
            {
                x = x_next;
            }
            else
            {
                x = x_next - 1;
            }
        }
        return x;
    }
};

class Solution1
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        int mx = *max_element(nums.begin(), nums.end());
        int high_bit = mx ? 31 - __builtin_clz(mx) : -1;

        int ans = 0, mask = 0;
        unordered_set<int> seen;
        for (int i = high_bit; i >= 0; i--)
        { // 从最高位开始枚举
            seen.clear();
            mask |= 1 << i;
            int new_ans = ans | (1 << i); // 这个比特位可以是 1 吗？
            for (int x : nums)
            {
                x &= mask; // 低于 i 的比特位置为 0
                if (seen.count(new_ans ^ x))
                {
                    ans = new_ans; // 这个比特位可以是 1
                    break;
                }
                seen.insert(x);
            }
        }
        return ans;
    }
};

int main()
{
    Solution1 s;
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    int x = s.findMaximumXOR(nums);
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