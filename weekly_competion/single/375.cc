#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <math.h>
#include <numeric>
using namespace std;
class Solution
{
public:
    // 计算a的c次方对k取模的结果
    int my_pow(int a, int c, int k)
    {
        // 保证每个因子都小于base
        a %= k;
        int res = 1;
        for (int i = 0; i < c; i++)
        {
            // 两两相乘
            res *= a;
            // 对乘法结果求模
            res %= k;
        }
        return res;
    }

    long long quick_muti(int x, int n)
    {
        long long ans = 1;
        int x_count = x;
        while (n)
        {
            if (n % 2 == 1)
            {
                ans *= x_count;
            }
            x_count *= x_count;
            n = n >> 1;
        }
        return ans;
    }

    /*
    ((aibi % 10)ci) % mi == target

    ((a+b) % p⋅c) % p=((a⋅c) % p+(b⋅c) % p) % p

    ((aibi % 10)ci) % mi = c


    */
    vector<int> getGoodIndices(vector<vector<int>> &var, int target)
    {
        int n = var.size();
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            int a = var[i][0], b = var[i][1], c = var[i][2], m = var[i][3];
            // int temp = quick_muti(a, b) % 10;
            // if (quick_muti(temp, c) % m == target)
            // {
            //     res.emplace_back(i);
            // }

            int temp1 = my_pow(a, b, 10);
            if (my_pow(temp1, c, m) == target)
            {
                res.emplace_back(i);
            }
        }
        return res;
    }
};

class Solution1
{
public:
    /*

    nums = [1,3,2,3,3], k = 2  最大元素出现k次

    */
    long long countSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        long long res = 0;
        int max_ele = *max_element(nums.begin(), nums.end());
        unordered_map<int, int> need, window;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int left = 0, right = 0;

        while (right < n && need[nums[right]] < k)
        {
            while (right < n && need[nums[right]] < k)
            {

                if (nums[right] == max_ele)
                {
                    need[nums[right]]++;
                }
                right++;
            }
            right--;
            res += n - right;
            while (need[nums[max_ele]] == k)
            {
                if (nums[left] != max_ele)
                {
                    left++;
                }
                res += left;
                if (nums[left] == max_ele)
                {
                    need[nums[max_ele]]--;
                    right++;
                    left++;
                }
            }
        }

        return res;
    }
};
int main()
{
    /*
     1 4 10   19

     1 2 4 8 10

     从前面的一个数中选一个，
    */

    // vector<int> coins = {1, 4, 10};
    // int target = 19;
    // Solution s;
    // int res = s.minimumAddedCoins(coins, target);

    // Solution1 s;
    // string str = "igigee";
    // int k = 2;
    // int res = s.countCompleteSubstrings(str, k);
    // cout << res;

    // Solution5 s;
    // string str = "zyxyxyz";
    // int res = s.removeAlmostEqualCharacters(str);
    // cout << res;
    // return 0;

    Solution1 s;
    vector<int> nums = {1, 3, 2, 3, 3};
    long long res = s.countSubarrays(nums, 2);
    cout << res;
    return 0;
}
