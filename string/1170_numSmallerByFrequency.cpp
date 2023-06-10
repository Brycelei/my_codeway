#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words)
    {
        vector<int> res;
        int n = queries.size();
        int m = words.size();
        auto f = [](string s)
        {
            int cnt[26] = {0};
            for (char c : s)
            {
                cnt[c - 'a']++;
            }
            for (int x : cnt)
            {
                if (x)
                {
                    return x;
                }
            }
            return 0;
        };

        int nums[m];
        for (int i = 0; i < m; i++)
        {
            nums[i] = f(words[i]);
        }
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < m; j++)
            {
                if (f(queries[i]) < f(words[j]))
                {
                    cnt++;
                }
            }
            res.emplace_back(cnt);
        }
        return res;
    }
};
int main()
{
    vector<string> querise = {"bba",
                              "abaaaaaa", "aaaaaa", "bbabbabaab", "aba", "aa", "baab", "bbbbbb", "aab", "bbabbaabb"};
    vector<string> words = {"aaabbb",
                            "aab", "babbab", "babbbb", "b", "bbbbbbbbab", "a", "bbbbbbbbbb", "baaabbaab", "aa"};
    Solution s;
    vector<int> res = s.numSmallerByFrequency(querise, words);
    for (auto &x : res)
    {
        std::cout << x << endl;
    }
    return 0;
}