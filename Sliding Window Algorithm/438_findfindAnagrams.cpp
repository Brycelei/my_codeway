#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <stack>
#include <functional>
#include <unordered_map>
using namespace std;
// https://leetcode.cn/problems/find-all-anagrams-in-a-string/solutions/9749/hua-dong-chuang-kou-tong-yong-si-xiang-jie-jue-zi-/
class Solution
{
public:
    vector<int> findAnagrams(string s, string t)
    {
        unordered_map<char, int> need, window;
        for (char c : t)
            need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        vector<int> res; // 记录结果
        while (right < s.size())
        {
            char c = s[right];
            right++;
            // 进行窗口内数据的一系列更新
            if (need.count(c))
            {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }
            // 判断左侧窗口是否要收缩
            while (right - left >= t.size())
            {
                // 当窗口符合条件时，把起始索引加入 res
                if (valid == need.size())
                    res.push_back(left);
                char d = s[left];
                left++;
                // 进行窗口内数据的一系列更新
                if (need.count(d))
                {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return res;
    }
};

int main()
{
    string str = "cbaebabacd";
    string p = "aab";
    Solution s;
    vector<int> res = s.findAnagrams(str, p);
    return 0;
}