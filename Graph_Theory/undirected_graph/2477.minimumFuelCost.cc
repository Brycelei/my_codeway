#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Solution
{
public:
    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        int n = roads.size();
        vector<vector<int>> g(n + 1);
        for (auto &e : roads)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        long long res = 0;
        function<int(int, int)> dfs = [&](int cur, int fa) -> int
        {
            int peopleSum = 1;
            for (auto ne : g[cur])
            {
                if (ne != fa)
                {
                    int peopleCnt = dfs(ne, cur);
                    peopleSum += peopleCnt;
                    res += (peopleCnt + seats - 1) / seats;
                }
            }
            return peopleSum;
        };
        dfs(0, -1);
        return res;
    }
};

/*


dfs
*/

int main()
{

    vector<vector<int>> roads = {{3, 1}, {3, 2}, {1, 0}, {0, 4}, {0, 5}, {4, 6}};
    int seats = 2;
    Solution s;
    int res = s.minimumFuelCost(roads, 2);
    cout << res << endl;
    return 0;
}