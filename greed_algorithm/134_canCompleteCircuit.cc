#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        vector<int> gastemp = gas;
        for (auto x : gas)
        {
            gastemp.emplace_back(x);
        }
        int n = gastemp.size();
        int m = cost.size();
        int begingas = 0;
        int res = 0;
        for (int i = 0, j = 0; i < n; i++)
        {
            begingas = begingas + gastemp[i];

            if (begingas - cost[i % (n >> 1)] < 0)
            {
                j = i + 1;
                begingas = 0;
                continue;
            }
            else
            {
                begingas = begingas - cost[i % (n >> 1)];
            }
            if (i > j && i % (n / 2) == j)
            {
                res = j;
                return res;
            }
        }
        return -1;
    }
};
int main()
{
    vector<int> vec1 = {2, 3, 4};
    vector<int> vec2 = {3, 4, 3};

    Solution s;
    int res = s.canCompleteCircuit(vec1, vec2);
    cout << res << endl;
    return 0;
}