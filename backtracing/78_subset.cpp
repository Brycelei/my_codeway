#include <iostream>
#include <vector>
using namespace std;
// 输入的角度看问题
class Solution1
{
public:
    vector<int> temp;
    vector<vector<int>> path;
    vector<vector<int>> subsets(vector<int> &nums)
    {
        backtrack(nums, 0);
        return path;
    }
    void backtrack(vector<int> &nums, int cur)
    {
        if (cur == nums.size())
        {
            path.emplace_back(temp);
            return;
        }
        temp.push_back(nums[cur]);
        backtrack(nums, cur + 1);
        temp.pop_back();
        backtrack(nums, cur + 1);
    }
};

struct node
{ // 定义一个新的类型叫node
    int a = 2;
    int b[110];
    char c;
    double d;
}; // 别忘了分号，毕竟这是个语句呢

// 站在答案的角度去看问题
class Solution2
{
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsets(vector<int> &nums)
    {
        backtrack(nums, path, 0);
        return res;
    }
    void backtrack(vector<int> &nums, vector<int> path, int start)
    {
        res.emplace_back(path); // 枚举第一个空
        for (int i = start; i < nums.size(); i++)
        {
            path.emplace_back(nums[i]);
            backtrack(nums, path, i + 1);
            path.pop_back();
        }
    }
};

int main()
{
    vector<int> vec = {1, 2, 3};
    Solution1 s;
    vector<vector<int>> res;
    res = s.subsets(vec);
    node nodea;
    cout << sizeof(nodea);
    cout << &nodea << "\n";
    cout << *(int *)&nodea;
    return 0;
}
