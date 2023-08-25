#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // 创建桶(数组)，设定128个元素对应0-127ASCII码值，全部赋0
        vector<int> m(128, 0);
        // 存最大长度
        int maxlen = 0;
        // head表示窗口最左边的字母序号：如果出现重复的，比如两个相同的字母a，上一个a在桶里存的m[s[i]]是a+1表示a的下一个位置
        // 那么第二个a出现时，head就=a+1也就是max(head,m[s[i]])，去除了窗口里上一个a，保证窗口里无重复字母
        int head = 0;
        // 遍历字符串
        for (int i = 0; i < s.size(); i++)
        {
            // 修改最左边的字母序号head
            head = max(head, m[s[i]]);
            // 当前字母对应的ASCII码桶里存下一个位置(i+1)，用于更新head
            m[s[i]] = i + 1;
            // 更新长度
            maxlen = max(maxlen, i - head + 1);
        }
        return maxlen;
    }
    /*
     滑动窗口
     左指针 i， 右指针 j
     用hash表来存放每个字母最后一次出现的位置 index,
     遍历 j
     每轮更新左指针i，保证区间 [i+1,j] 内无重复字符且最大。
     更新最大值res
    */
    int lengthOfLongestSubstring1(string s)
    {
        unordered_map<char, int> umap;
        int i = -1, res = 0, len = s.size();

        for (int j = 0; j < len; j++)
        {
            if (umap.find(s[j]) != umap.end())
            {
                i = max(i, umap.find(s[j])->second);
                // cout<<i<<"mmmm";
            }
            umap[s[j]] = j;
            res = max(res, j - i);
        }
        return res;
    }
};

int main()
{
    string str = "abcabcbb";
    Solution s;
    int res = s.lengthOfLongestSubstring1(str);
    return 0;
}