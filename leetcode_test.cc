#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <map>
using namespace std;
class Solution1
{
public:
    vector<int> lastVisitedIntegers(vector<string> &words)
    {
        vector<int> res;
        vector<int> a;
        int l = 0;
        for (auto &q : words)
        {
            if (q == "prev")
            {
                ++l;
                if (a.size() < l)
                {
                    res.push_back(-1);
                }
                else
                {
                    res.push_back(a[a.size() - l]);
                }
            }
            else
            {
                l = 0;
                a.push_back(stoi(q));
            }
        }
        return res;
    }
};
class Solution
{
public:
    vector<string> getWordsInLongestSubsequence(int k, vector<string> &words, vector<int> &groups)
    {
        int n = groups.size();
        vector<string> vstr;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }
        int maxlen = 1;
        int start = 0, end = 0;
        function<int(string, string)> f1 = [&](string s1, string s2) -> int
        {
            int count = 0;
            for (int i = 0; i < s1.size(); i++)
            {
                if (s1[i] != s2[i])
                    count++;
            }
            return count;
        };
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (groups[j] != groups[j - 1] && words[i].size() == words[j].size() && f1(words[i], words[j]) == 1)
                {
                    dp[i][j] = dp[i][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                    // break;
                }
                if (dp[i][j] > maxlen)
                {
                    start = i;
                    end = j;
                }
                maxlen = max(dp[i][j], maxlen);
            }
        }
        cout << maxlen;
        for (int i = start; i <= end; i++)
        {
            vstr.emplace_back(words[i]);
        }
        return vstr;
    }
};

class Solution2
{
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        int n = s.size();
        int len = INT_MAX;
        vector<string> vec;
        //"100011001"
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i + 1; j++)
            {
                if (s[i] == '1')
                {
                    string str = s.substr(i, j);
                    if (count(str) == k)
                    {
                        // len = j - i;
                        if (j - i <= len)
                        {
                            len = j - 1;
                            vec.emplace_back(str);
                        }
                    }
                }
            }
        }
        int temp = INT16_MAX;
        // for (int i = 1; i < vec.size(); i++)
        // {
        //     if (vec[i].size() < temp)
        //     {
        //         return vec[i];
        //     }
        // }
        sort(vec.begin(), vec.end(), [&](auto a, auto b)
             { return a.size() < b.size(); });
        int move = vec[0].size();
        int changdu = 0;
        unordered_map<int, int> umap;
        for (int i = 0; i < vec.size(); i++)
        {
            if (move = vec[i].size())
            {
                for (int j = 1; j < move; j++)
                {
                    if (vec[i][j] == '0')
                    {
                        umap[i] = j;
                        break;
                    }
                }
            }
        }
        int ans = 0;
        for (auto &[x, y] : umap)
        {
            if (y < temp)
            {
                ans = y;
            }
            temp = y;
        }
        return vec[ans];
    }
    int count(string &s)
    {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                count++;
            }
        }
        return count;
    }
};

class Solution3
{
public:
    vector<int> findIndices(vector<int> &nums, int indexDifference, int valueDifference)
    {
        int n = nums.size();
        map<int, int> mp;
        for (int r = 0; r < n; r++)
        {
            int l = r - indexDifference;
            if (l >= 0)
            {
                mp[nums[l]] = l;
            }
            if (mp.size())
            {
                auto it = mp.begin();
                if (it->first <= nums[r] - valueDifference)
                {
                    return {it->second, r};
                }
                it = prev(mp.end());
                if (it->first >= nums[r] + valueDifference)
                {
                    return {it->second, r};
                }
            }
        }
        return {-1, -1};
    }
};

int main()
{
    // Solution A;
    // vector<string> words = {"bab", "dab", "cab"};
    // vector<int> g = {
    //     1,
    //     2, 2};
    // int k = 3;
    // vector<string> ans = A.getWordsInLongestSubsequence(k, words, g);
    // for (auto &x : ans)
    // {
    //     cout << x << endl;
    // }

    // Solution1 b;
    // vector<string> words1 = {"1", "2", "prev", "prev", "prev"};
    // vector<int> res = b.lastVisitedIntegers(words1);

    Solution2 c;
    string str = {"001110101101101111"};
    string res = c.shortestBeautifulSubstring(str, 10);

    return 0;
}
