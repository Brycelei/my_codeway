#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        stack<pair<int, int>> st; // {idx, 开始运行的时间}
        vector<int> res(n, 0);
        for (auto &log : logs)
        {
            char type[10];
            int idx, timestamp;
            sscanf(log.c_str(), "%d:%[^:]:%d", &idx, type, &timestamp);
            if (type[0] == 's')
            {
                if (!st.empty())
                {
                    res[st.top().first] += timestamp - st.top().second;
                    st.top().second = timestamp;
                }
                st.emplace(idx, timestamp);
            }
            else
            {
                auto t = st.top();
                st.pop();
                res[t.first] += timestamp - t.second + 1;
                if (!st.empty())
                {
                    st.top().second = timestamp + 1;
                }
            }
        }
        return res;
    }
};

int main()
{
    class Solution A;
    vector<int> res;
    vector<string> logs = {{"0:start:0"}, {"1:start:2"}, {"1:end:5"}, {"0:end:6"}};
    res = A.exclusiveTime(2, logs);
    for (auto &x : res)
    {
        cout << x << endl;
    }
    return 0;
}
