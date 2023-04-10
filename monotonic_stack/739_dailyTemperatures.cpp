#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> sta;
        // int x = 0;
        int n = temperatures.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++)
        {
            while (!sta.empty() && temperatures[sta.top()] < temperatures[i])
            {
                int a = sta.top();
                res[a] = i - a;
                sta.pop();
            }
            sta.emplace(i);
        }
        return res;
    }
};

int main()
{
    vector<int> vec{73, 74, 75, 71, 69, 72, 76, 73};
    Solution A;
    vector<int> result = A.dailyTemperatures(vec);
    for (auto &x : result)
    {
        cout << x << "\n";
    }
    return 0;
}
