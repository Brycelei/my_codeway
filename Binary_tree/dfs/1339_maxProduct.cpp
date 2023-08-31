#include ".\self_definition\TreeNode.h"
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int maxProduct(TreeNode *root)
    {
        vector<int> vec;
        int maxnum = 0;
        dfs(root, maxnum, vec);
        long long res = 0, mod = 1e9 + 7;
        for (auto &num : vec)
        {
            res = max(res, ((long long)num * (maxnum - num)));
        }
        return res % mod;
    }
    /*
        dfs将以每个节点划分两部分后，将以其中一个节点为根节点的树的和存储在`vector`中，
        整个树的最大和为`maxnum`.
    */
    int dfs(TreeNode *root, int &maxnum, vector<int> &vec)
    {
        if (!root)
            return 0;
        int left = dfs(root->left, maxnum, vec);
        int right = dfs(root->right, maxnum, vec);
        int sum = root->val + left + right;
        if (maxnum < sum)
        {
            maxnum = sum;
        }
        vec.emplace_back(sum);
        return sum;
    }
};

int main()
{
    return 0;
}