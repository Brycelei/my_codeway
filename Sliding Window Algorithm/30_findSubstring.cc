#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        int n = s.size();
        int stride = words[0].size();
        int limit = words.size() * stride;

        unordered_map<string, int> need;
        for (auto w : words)
        {
            need[w]++;
        }
        vector<int> ans;
        // 枚举起点
        for (int start = 0; start <= stride - 1; start++)
        {
            // left 和 right 指向的是当前步子的第一个下标
            int left = start;
            int right = start;
            int cnt = 0; // 记录窗口内满足要求的单词数量
            unordered_map<string, int> window;
            while (right < n)
            {
                // 右边届入窗
                string cur_right = s.substr(right, stride);
                if (need.count(cur_right))
                {
                    window[cur_right]++;
                    if (window[cur_right] == need[cur_right])
                    {
                        cnt++;
                    }
                }
                // 左边届收缩
                if (right - left + stride > limit)
                {
                    string cur_left = s.substr(left, stride);
                    if (need.count(cur_left))
                    {
                        if (window[cur_left] == need[cur_left])
                        {
                            cnt--;
                        }
                        window[cur_left]--;
                    }
                    left += stride;
                }
                // 采集答案
                if (right - left + stride == limit && cnt == need.size())
                {
                    ans.push_back(left);
                }
                right += stride;
            }
        }

        return ans;
    }
};

int main()
{
    string str = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    Solution s;
    vector<int> res = s.findSubstring(str, words);
    for (auto &x : res)
    {
        std::cout << x << endl;
    }
    return 0;
}