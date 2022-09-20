#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class Solution
{
public:
    string reorderSpaces(string text)
    {
        vector<string> vec;    //用数组保存单词
        stringstream in(text); //构造string流
        string word, ans;
        int cnt = 0;
        while (in >> word) //不断获取单词，存入vec中
        {
            vec.push_back(word);
            cnt += word.size(); //记录单词总长度
        }
        if (vec.size() == 1) //如果只有一个单词，单独处理
            ans = vec[0];
        else
        {
            string space((text.size() - cnt) / (vec.size() - 1), ' '); //计算并生成单词间的空格
            for (int i = 0; i < vec.size() - 1; ++i)                   //重新生成字符串，最后一个单独处理
                ans += vec[i] + space;
            ans += vec.back();
        }
        return ans + string(text.size() - ans.size(), ' '); //用空格补齐并返回
    }
};
int main()
{
    string s = "I speak Goat Latin";
    Solution A;
    string res = A.reorderSpaces(s);
    cout << res;
    return 0;
}