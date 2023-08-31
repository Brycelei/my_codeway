#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    const int mod = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<long long> dp(n, 1);                    // 一个根结点单独成树是一种情况
        vector<long long> vec{arr.begin(), arr.end()}; // 将类型保存为long long防止溢出
        for (int i = 1; i < n; ++i)
        {
            int l = 0, r = i - 1;
            while (l <= r)
            {
                long long mul = vec[l] * vec[r];
                if (mul < vec[i])
                    l++;
                else if (mul > vec[i])
                    r--;
                else
                {
                    dp[i] += dp[l] * dp[r] * (l == r ? 1 : 2);
                    l++;
                    r--;
                }
            }
            dp[i] %= mod;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans += dp[i];
            ans %= mod;
        }
        return ans;
    }
};

/*
    先对数组排序，如图所示，初始化dp数组
    以某个节点可以构成二叉树的个数
    dp[i]表示以 节点arr[i]w为根节点的个数，枚举左右节点，如果左右节点想等则取1，否则取2倍
    dp[i] += dp[l] * dp[r] * (l == r ? 1 : 2);
    以2为根节点的个数为 1
    以3为根节点的个数为 1
    以6为根节点的个数为 3
    以18为根节点的个数为 7

*/

// 2 3 6 18

int main()
{
    vector<int> vec = {18, 3, 6, 2};
    class Solution A;
    A.numFactoredBinaryTrees(vec);
    return 0;
}