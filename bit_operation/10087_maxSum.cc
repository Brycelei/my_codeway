#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSum(vector<int> &nums, int k)
    {
        const int MOD = 1'000'000'007;
        int cnt[30]{};
        for (int x : nums)
        {
            for (int i = 0; i < 30; i++)
            {
                cnt[i] += (x >> i) & 1;
            }
        }
        long long ans = 0;
        while (k--)
        {
            int x = 0;
            for (int i = 0; i < 30; i++)
            {
                if (cnt[i] > 0)
                {
                    cnt[i]--; // 用完了要减去
                    x |= 1 << i;
                    if (k == 1)
                    {
                        cout << x << endl;
                    }
                }
            }
            ans = (ans + (long long)x * x) % MOD;
        }
        return ans;
    }
};

int main()
{
    int a = 10;
    Solution s;
    vector<int> nums = {2, 6, 5, 8};

    int res = s.maxSum(nums, 2);
    cout << res;
    return 0;
}
