#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        int n = dist.size();
        vector<int> arrivalTimes(n);
        for (int i = 0; i < n; i++)
        {
            arrivalTimes[i] = (dist[i] - 1) / speed[i] + 1; // 向上取整
        }
        sort(arrivalTimes.begin(), arrivalTimes.end());
        for (int i = 0; i < n; i++)
        {
            if (arrivalTimes[i] <= i)
            {
                return i;
            }
        }
        return n;
    }
};

int main()
{
    vector<int> vec1 = {4, 8, 6, 8, 2, 7, 4};
    vector<int> vec2 = {1, 3, 3, 1, 10, 1, 1};
    Solution s;
    int res = s.eliminateMaximum(vec1, vec2);
    cout << res << endl;
    return 0;
}

// 4 3 3 3 1 记录最小数字的编号
