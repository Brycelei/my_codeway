#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <numeric>
using namespace std;

class Solution
{
public:
    int distributeCandies(int n, int limit)
    {
        vector<int> a(limit + 1);
        vector<int> b(limit + 1);
        vector<int> c(limit + 1);
        iota(a.begin(), a.end(), 0);
        iota(b.begin(), b.end(), 0);
        iota(c.begin(), c.end(), 0);

        int res = 0;
        for (int i = 0; i <= limit; i++)
        {
            for (int j = 0; j <= limit; j++)
            {
                for (int k = 0; k <= limit; k++)
                {
                    if (a[i] + b[j] + c[k] == n)
                    {
                        cout << i << " " << j << " " << k << endl;
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
class Solution1
{
public:
    long long distributeCandies(int n, int limit)
    {
        long long ans = 0;
        for (int i = 0; i <= limit; ++i)
        {
            if (i > n)
                break;
            int x = n - i;
            int l = max(0, x - limit);
            int r = min(x, limit);
            if (l <= r)
                ans += (r - l + 1);
        }
        return ans;
    }
};
int main()
{
    Solution1 s;
    int a = s.distributeCandies(5, 2);
    cout << a;
    return 0;
}
