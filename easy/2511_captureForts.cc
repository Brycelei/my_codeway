#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
using namespace std;

class Solution
{
public:
    int captureForts(vector<int> &forts)
    {
        int pre = 0, ans = 0;
        for (int i = 0; i < forts.size(); ++i)
        {
            if (forts[i] != 0)
            {
                if (forts[i] + forts[pre] == 0)
                    ans = max(ans, i - pre - 1);
                pre = i;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    // 1, 0, 0, -1, 0, 0, -1, 0, 0, 1
    vector<int> vec = {1, -1, -1, 1, 1};
    int res = s.captureForts(vec);
    cout << res;
}