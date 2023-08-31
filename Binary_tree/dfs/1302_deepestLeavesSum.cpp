#include ".\self_definition\TreeNode.h"
#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    int deepestLeavesSum(TreeNode *root)
    {
        queue<TreeNode *> que;
        if (!root)
            return root->val;
        que.push(root);
        vector<vector<int>> res;
        while (!que.empty())
        {
            int n = que.size();
            vector<int> temp;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = que.front();
                temp.emplace_back(node->val);
                que.pop();
                if (node->left)
                    que.emplace(node->left);
                if (node->right)
                    que.emplace(node->right);
            }
            res.emplace_back(temp);
        }
        int m = res.size() - 1;
        return accumulate(res[m].begin(), res[m].end(), 0);
    }
};