#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int flipgame(vector<int> &fronts, vector<int> &backs)
    {
        int res = 3000, n = fronts.size();
        unordered_set<int> same;
        for (int i = 0; i < n; ++i)
        {
            if (fronts[i] == backs[i])
            {
                same.insert(fronts[i]);
            }
        }
        for (int &x : fronts)
        {
            if (x < res && same.count(x) == 0)
            {
                res = x;
            }
        }
        for (int &x : backs)
        {
            if (x < res && same.count(x) == 0)
            {
                res = x;
            }
        }
        return res % 3000;
    }
};

int main()
{
    Solution s;
    vector<int> fronts = {1, 2, 4, 4, 7};
    vector<int> backs = {1, 3, 4, 1, 3};
    int res = s.flipgame(fronts, backs);
    cout << res;
    return 0;
}