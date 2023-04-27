
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
// C++
class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        unordered_map<string, int> cnt;
        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.size() < b.size(); });
        int res = 0;
        for (string word : words)
        {
            cnt[word] = 1;
            for (int i = 0; i < word.size(); i++)
            {
                string prev = word.substr(0, i) + word.substr(i + 1);
                if (cnt.count(prev))
                {
                    cnt[word] = max(cnt[word], cnt[prev] + 1);
                }
            }
            res = max(res, cnt[word]);
        }
        return res;
    }
};

int main()
{
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    Solution s;
    int res = s.longestStrChain(words);
    return 0;
}