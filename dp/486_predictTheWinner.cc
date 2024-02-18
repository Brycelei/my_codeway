#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <stack>
#include <functional>
using namespace std;
class Solution1
{
public:
    bool predictTheWinner(vector<int> &nums)
    {
        function<int(int, int)> dfs = [&](int i, int j) -> int
        {
            if (i == j)
            {
                return nums[i];
            }
            int play1 = nums[i] - dfs(i + 1, j);
            int play2 = nums[j] - dfs(i, j - 1);
            return max(play1, play2); // 胜过对方的分数
        };
        return dfs(0, nums.size() - 1) >= 0;
    }
};
// 记忆话搜索
class Solution2
{
public:
    bool predictTheWinner2(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        function<int(int, int)> dfs = [&](int i, int j) -> int
        {
            if (i == j)
            {
                return nums[i];
            }
            if (memo[i][j] != -1)
            {
                return memo[i][j];
            }
            int play1 = nums[i] - dfs(i + 1, j);
            int play2 = nums[j] - dfs(i, j - 1);
            memo[i][j] = max(play1, play2);
            return memo[i][j]; // 胜过对方的分数
        };
        return dfs(0, nums.size() - 1) >= 0;
    }
};

// 记忆话搜索转dp
class Solution
{
public:
    bool predictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        function<int(int, int)> dfs = [&](int i, int j) -> int
        {
            if (i == j)
            {
                return nums[i];
            }
            if (memo[i][j] != -1)
            {
                return memo[i][j];
            }
            int play1 = nums[i] - dfs(i + 1, j);
            int play2 = nums[j] - dfs(i, j - 1);
            memo[i][j] = max(play1, play2);
            return memo[i][j]; // 胜过对方的分数
        };
        return dfs(0, nums.size() - 1) >= 0;
    }
};

/*
1 5 233 7

贪心肯定是有问题的

枚举玩家的所有会的选择


选 nums[0]  nums(1, n-1)

选 nums[n-1] nums(0, n - 2)

如开始的思路，其实就是定义dfs为此次选择的最大值


dfs(i, j)


画图很重要
dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i, j - 1]);


   j    0  1   2   3
i       1  5  233 7
0  1    1
1  5       5
2  233        233
3  7              7

从转移方式可以看出从下往上填填比较好
则 i= 2，j = 3
dp[2][3] =max{
    num[2] - dp[3][3]
    nums[3] - dp[3][2]
}


for(int i = n - 2; i >= 0; i--)
{
    for(int j = i+1, j < n; j++)
    {

    }
}

dp[n-2]
*/

int main()
{
    vector<int> vec = {18, 3, 6, 2};
    class Solution A;
    A.predictTheWinner(vec);
    return 0;
}