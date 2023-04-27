#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <stack>
#include <functional>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> need, window;
        for (auto &x : t)
        {
            need[x]++;
        }
        int left = 0, right = 0, valid = 0;
        int start = 0, len = INT_MAX;
        while (right < s.size())
        {
            char c = s[right];
            right++; // continue go right
            if (need.count(c))
            {
                window[c]++;
                if (window[c] == need[c])
                {
                    valid++;
                }
            }
            while (valid == need.size())
            {
                if (right - left < len)
                {
                    start = left;
                    len = right - start;
                }
                char d = s[left];
                left++;
                if (need.count(d))
                {
                    if (window[d] == need[d])
                    {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

int main()
{
    string str = "ADOBECODEBANC";
    string p = "ABC";
    Solution s;
    string res = s.minWindow(str, p);
    return 0;
}