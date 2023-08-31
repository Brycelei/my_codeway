#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int u = 0, d = n - 1, l = 0, r = n - 1;
        vector<vector<int>> res(n, vector<int>(n, 0));
        int start = 1;
        int row = 0, col = 0;
        int end = n * n;
        while (start <= end)
        {
            for (int i = l; i <= r; i++)
                res[u][i] = start++;
            u++;
            for (int i = u; i <= d; i++)
                res[i][r] = start++;
            r--;
            for (int i = r; i >= l; i--)
                res[d][i] = start++;
            d--;
            for (int i = d; i >= u; i--)
                res[i][l] = start++;
            l++;
        }
        return res;
    }
};
int main()
{
    int n = 3;
    class Solution A;
    A.generateMatrix(n);
    return 0;
}