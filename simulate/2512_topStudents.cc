#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
#include <sstream>
using namespace std;
class Solution
{
public:
    vector<int> topStudents(vector<string> &positive_feedback, vector<string> &negative_feedback, vector<string> &report, vector<int> &student_id, int k)
    {
        unordered_map<std::string, int> words;
        for (const auto &word : positive_feedback)
        {
            words[word] = 3;
        }
        for (const auto &word : negative_feedback)
        {
            words[word] = -1;
        }
        vector<vector<int>> A;
        for (int i = 0; i < report.size(); i++)
        {
            stringstream ss; // stream根据空格分词
            string w;
            int score = 0;
            ss << report[i];
            while (ss >> w)
            {
                if (words.count(w))
                {
                    score += words[w];
                }
            }
            A.push_back({-score, student_id[i]});
        }
        sort(A.begin(), A.end());
        vector<int> top_k;
        for (int i = 0; i < k; i++)
        {
            top_k.push_back(A[i][1]);
        }
        return top_k;
    }
};
int main()
{
    int n = 3;
    class Solution A;
    vector<string> positive_feedback = {"fkeofjpc", "qq", "iio"};
    vector<string> negative_feedback = {"jdh", "khj", "eget", "rjstbhe", "yzyoatfyx", "wlinrrgcm"};
    vector<string> report = {"rjstbhe eget kctxcoub urrmkhlmi yniqafy fkeofjpc iio yzyoatfyx khj iio", "gpnhgabl qq qq fkeofjpc dflidshdb qq iio khj qq yzyoatfyx", "tizpzhlbyb eget z rjstbhe iio jdh jdh iptxh qq rjstbhe", "jtlghe wlinrrgcm jnkdbd k iio et rjstbhe iio qq jdh", "yp fkeofjpc lkhypcebox rjstbhe ewwykishv egzhne jdh y qq qq", "fu ql iio fkeofjpc jdh luspuy yzyoatfyx li qq v", "wlinrrgcm iio qq omnc sgkt tzgev iio iio qq qq", "d vhg qlj khj wlinrrgcm qq f jp zsmhkjokmb rjstbhe"};
    vector<int> student_id = {96537918, 589204657, 765963609, 613766496, 43871615, 189209587, 239084671, 908938263};
    A.topStudents(positive_feedback, negative_feedback, report, student_id, 3);
    return 0;
}