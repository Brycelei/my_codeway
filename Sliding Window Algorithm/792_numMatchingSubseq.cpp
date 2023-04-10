#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <stack>
#include <functional>
using namespace std;

class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.size(); ++i)
        {
            pos[s[i] - 'a'].push_back(i);
        }
        int res = words.size();
        for (auto &w : words)
        {
            if (w.size() > s.size())
            {
                --res;
                continue;
            }
            int p = -1;
            for (char c : w)
            {
                auto &ps = pos[c - 'a'];
                auto it = upper_bound(ps.begin(), ps.end(), p);
                //第一个大于p的元素
                if (it == ps.end())
                {
                    --res;
                    break;
                }
                p = *it;
            }
        }
        return res;
    }
    int nummatch(string s, vector<string> &word)
    {
        int n = word.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (s.find(word[i]) != string::npos)
            {
                ++count;
            }
        }
        return count;
    }
};

int main()
{
    Solution so;
    string s = "abcde";
    vector<string> words = {"a", "bb", "acd", "ace"};
    // int a = so.numMatchingSubseq(s, words);
    int b = so.nummatch(s, words);
    return 0;
}