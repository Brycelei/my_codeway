#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int res = 0;
        int n = seats.size();
        // 枚举所有的1
        int start = 0, end = 0;
        for (int i = 0; i < n; i++)
        {
            if (seats[i] == 0)
            {
                start = i;
                end = i;
                for (int j = i + 1; j < n; j++)
                {
                    if (seats[j] == 0)
                    {
                        end++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            /*3种情况
            0开始的
            0 结束的
            0 在中间的
            */
            if (end == n - 1)
            {
                res = max(end - start + 1, res);
            }
            if (start == 0 && end != 0)
            {
                res = max(end - start + 1, res);
            }
            else
            {
                res = max((end - start + 2) >> 1, res);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {
        1,
        0,
        0,
        0,
        1,
        0,
    };
    int res = s.maxDistToClosest(vec);
    cout << res;
}