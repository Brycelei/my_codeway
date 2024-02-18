#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <math.h>
#include <numeric>
using namespace std;
class Solution1
{
public:
    int findKOr(vector<int> &nums, int k)
    {
        int n = nums.size();
        int res = 0;
        int low_bit[4]{};

        if (k == 1)
        {
            for (auto &x : nums)
            {
                res |= x;
            }
        }
        else if (k == n)
        {
            // res = 1;
            for (auto &x : nums)
            {
                res &= x;
            }
        }
        else
        {

            int temp = k;
            for (auto &x : nums)
            {
                while (temp-- && x)
                {
                    if (x % 2 == 1)
                    {
                        low_bit[temp]++;
                    }
                    x = x >> 1;
                }
                temp = k;
            }
            for (int i = 0; i < k; i++)
            {
                if (low_bit[i] >= k)
                {
                    res += pow(2, i);
                }
            }
        }
        return res;
    }
};

class Solution1_1
{
public:
    int findKOr(vector<int> &nums, int k)
    {
        int ans = 0;
        for (int i = 0; i < 31; i++)
        {
            int cnt1 = 0;
            for (int x : nums)
            {
                cnt1 += (x >> i) & 1;
            }
            if (cnt1 >= k)
            {
                ans |= 1 << i;
            }
        }
        return ans;
    }
};

/*
nums = [7,12,9,8,9,15], k = 4

int low_bit[4]{};
*/

class Solution2
{
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        long long res = -1;
        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] == 0)
            {
                count1++;
            }
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            if (nums2[i] == 0)
            {
                count2++;
            }
        }

        long long sum1 = accumulate(nums1.begin(), nums1.end(), (long long)0);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), (long long)0);

        if (sum1 >= sum2)
            swap(nums1, nums2);
        if (sum1 + count1 < sum2 + count2)
            return sum2 + count2;
        else
            return -1;
    }
};
int main()
{
    Solution1_1 a;
    vector<int> nums2 = {2, 12, 1, 11, 4, 5};
    vector<int> nums1 = {22, 7, 27, 30, 15, 30, 28};
    vector<int> nums3 = {10, 8, 5, 9, 11, 6, 8};

    int res = a.findKOr(nums1, 4);

    Solution2 b;

    vector<int> nums4 = {0, 7, 28, 17, 18};
    vector<int> nums5 = {1, 2, 6, 26, 1, 0, 27, 3, 0, 30};

    vector<int> nums6 = {3, 2, 0, 1, 0};
    vector<int> nums7 = {6, 5, 0};

    vector<int> nums8 = {8, 13, 15, 18, 0, 18, 0, 0, 5, 20, 12, 27, 3, 14, 22, 0};
    vector<int> nums9 = {29, 1, 6, 0, 10, 24, 27, 17, 14, 13, 2, 19, 2, 11};
    long long ans = b.minSum(nums8, nums9);

    // long long ans = b.minSum(nums6, nums7);

    // long long ans = b.minSum(nums4, nums5);

    return 0;
}
