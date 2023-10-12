#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2)
    {
        if (cost1 < cost2)
            swap(cost1, cost2);
        long long ans = 0;
        for (int s = 0; s <= total; s += cost1)
            ans += 1 + (total - s) / cost2;
        return ans;
    }
};

/*
    固定钢笔的数目
    去看铅笔的数目
    i * cost1 + j * cost2 <= total
    枚举i，去看有多少个j；
*/
int main()
{
    int total = 100000, cost1 = 10, cost2 = 5;
    class Solution A;
    long long res = A.waysToBuyPensPencils(total, cost1, cost2);
    cout << res;
    return 0;
}