/**
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 * 此外，你可以假设该网格的四条边均被水包围。
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/number-of-islands
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>
#include <queue>
// bfs
using namespace std;
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    res++;
                    bfs(grid, i, j);
                }
            }
        }
        return res;
    }
    int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    void bfs(vector<vector<char>> &grid, int x, int y)
    {
        queue<pair<int, int>> que;
        que.push({x, y});
        grid[x][y] = 2;
        while (!que.empty())
        {
            int x = que.front().first, y = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++)
            {
                int newx = x + dir[i][0];
                int newy = y + dir[i][1];
                if (newx >= 0 && newx < grid.size() && newy >= 0 && newy < grid[0].size() && grid[newx][newy] == '1')
                {
                    grid[newx][newy] = 2;
                    que.push({newx, newy});
                }
            }
        }
    }
};
// dfs
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0; //初始化岛屿数量
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    count++; //每遍历到一个‘1’，岛屿数量加1
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        //如果当前坐标不在网格中，直接返回
        if (!inArea(grid, i, j))
            return;
        // 如果这个格子不是岛屿，直接返回
        if (grid[i][j] != '1')
            return;
        // 将已遍历过的格子标为‘2’
        grid[i][j] = '2';
        //类似于二叉树的前序遍历，向上下左右四个方向遍历
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
    // 判断坐标是否在网格中
    bool inArea(vector<vector<char>> &grid, int i, int j)
    {
        return (i >= 0) && (i < grid.size()) && (j >= 0) && (j < grid[0].size());
    }
};

int main()
{
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    Solution s;
    int res = s.numIslands(grid);
    return 0;
}