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
class Solution
{
public:
    int findMinimumOperations(string s1, string s2, string s3)
    {
        int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        int minlen = min(min(len1, len2), len3);
        int res = -1;
        if (minlen == len1)
        {
            for (int i = len1; i >= 0; i--)
            {
                string temp1 = s1.substr(0, i);
                string temp2 = s2.substr(0, i);
                string temp3 = s3.substr(0, i);
                if (temp1 == temp2 && temp1 == temp3 && !temp1.empty())
                {
                    res = len1 + len2 + len3 - 3 * i;
                    break;
                }
            }
        }
        else if (minlen == len2)
        {
            for (int i = len2; i >= 0; i--)
            {
                string temp1 = s1.substr(0, i);
                string temp2 = s2.substr(0, i);
                string temp3 = s3.substr(0, i);
                if (temp1 == temp2 && temp1 == temp3 && !temp1.empty())
                {
                    res = len1 + len2 + len3 - 3 * i;
                    break;
                }
            }
        }
        else if (minlen == len3)
        {
            for (int i = len3; i >= 0; i--)
            {
                string temp1 = s1.substr(0, i);
                string temp2 = s2.substr(0, i);
                string temp3 = s3.substr(0, i);
                if (temp1 == temp2 && temp1 == temp3 && !temp1.empty())
                {
                    res = len1 + len2 + len3 - 3 * i;
                    break;
                }
            }
        }
        return res;
    }
    int iscontain(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        string temp = s1.substr(0, m);
        if (temp == s2)
            return n - m;
        else
            return -1;
    }
};

class Solution2
{
public:
    long long minimumSteps(string s)
    {
        long long res = 0.0;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        int count = 0;
        if (s[0] == '1')
        {
            count = 1;
        }
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '1')
                count++;
            if (s[i - 1] == '1' && s[i] == '0')
            {
                dp[i] = dp[i - 1] + count;
            }
            if (dp[i - 1] != 0 && s[i] == '0')
            {
                dp[i] = dp[i - 1] + count;
            }
        }
        return dp[n - 1];
    }
};
int main()
{
    // Solution s;
    // string s1 = "dac";
    // string s2 = "bac";
    // string s3 = "cac";
    // int res = s.findMinimumOperations(s1, s2, s3);
    // cout << res;

    string s1 = "101";
    Solution2 s;
    long long res = s.minimumSteps(s1);
    return 0;
}
