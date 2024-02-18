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
    int minimumAddedCoins(vector<int> &coins, int target)
    {
        sort(coins.begin(), coins.end());
        int res = 0, s = 1, i = 0;
        while (s <= target)
        {
            // coins[i]为 x
            if (i < coins.size() && coins[i] <= s)
            {
                s += coins[i];
                cout << s << endl;
                i++;
            }
            else
            {
                s *= 2;

                res++;
            }
        }
        return res;
    }
};

class Solution1
{
    int countLetterSubstring(string s, int k, int count)
    {
        int res = 0;
        int left = 0, right = 0;
        int len = s.size();
        int window[26] = {0};
        int winValCnt = 0;
        while (right < len)
        {
            char c = s[right];
            right++;
            window[c - 'a']++;
            if (window[c - 'a'] == k)
                winValCnt++;

            while (right - left > k * count)
            {
                char d = s[left];
                left++;
                if (window[d - 'a'] == k)
                    winValCnt--;
                window[d - 'a']--;
            }

            if (winValCnt == count)
                res++;
        }

        return res;
    }

public:
    int countCompleteSubstrings(string word, int k)
    {
        int len = word.size();
        int left = 0, right = 0;
        vector<string> strs;
        while (right < len)
        {
            char c = word[right];
            right++;
            if (right == len || abs(word[right] - c) > 2)
            {
                strs.push_back(word.substr(left, right - left));
                left = right;
            }
        }

        int cnt = 0;
        for (string &str : strs)
            for (int i = 1; i <= 26; i++)
                cnt += countLetterSubstring(str, k, i);
        return cnt;
    }
};

class Solution5
{
public:
    int removeAlmostEqualCharacters(string word)
    {
        int n = word.size();
        int count = 0;
        int i = 0, j = 1;
        while (j < n && i < j)
        {
            int a = word[i] - '0', b = word[j] - '0';
            if (abs(a - b) <= 1)
            {
                count++;
                {
                    i += 2;
                    j += 2;
                }
            }
            else
            {
                i = j;
                j++;
            }
        }
        return count;
    }
};

//

/*
nums = [1,2,3,1,2,3,1,2], k = 2
dp[i][j] 表示最长的好子数组的长度

以j结束的，最长串的长度是 dp[j]





*/

class Solution6
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> need, window;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int left = 0, right = 0;
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }
        while (right < n)
        {
            need[nums[right]]++;
            if (need[nums[right]] > k)
            {
                dp[left][right] = right;
            }
            right++;
            // res = max(dp[left][right], 0);
        }
        res = dp[left][right];
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

    Solution6 s6;
    vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
    int res = s6.maxSubarrayLength(nums, 2);
    cout << res;
    return 0;
}
