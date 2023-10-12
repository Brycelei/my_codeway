// D:\Temp\mycode_way\self_definition\TreeNode.h
#include "../../self_definition/TreeNode.h"
#include <algorithm>
#include <functional>
using namespace std;
class Solution1
{
public:
    int rob(TreeNode *root)
    {
        return dfs(root);
    }
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->val;

        // steal parent
        int val1 = root->val;
        if (root->left)
            val1 += dfs(root->left->left) + dfs(root->left->right);
        if (root->right)
            val1 += dfs(root->right->left) + dfs(root->right->right);
        // do not steal parent
        int val2 = dfs(root->left) + dfs(root->right);
        return max(val1, val2);
    }
};

class Solution2
{
public:
    unordered_map<TreeNode *, int> umap; // 记录计算过的结果
    int rob(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return root->val;
        if (umap[root])
            return umap[root]; // 如果umap里已经有记录则直接返回
        // 偷父节点
        int val1 = root->val;
        if (root->left)
            val1 += rob(root->left->left) + rob(root->left->right); // 跳过root->left
        if (root->right)
            val1 += rob(root->right->left) + rob(root->right->right); // 跳过root->right
        // 不偷父节点
        int val2 = rob(root->left) + rob(root->right); // 考虑root的左右孩子
        umap[root] = max(val1, val2);                  // umap记录一下结果
        return max(val1, val2);
    }
};

class Solution3
{
public:
    int rob(TreeNode *root)
    {
        vector<int> result = robTree(root);
        return max(result[0], result[1]);
    }
    // 长度为2的数组，0：不偷，1：偷
    vector<int> robTree(TreeNode *cur)
    {
        if (cur == NULL)
            return vector<int>{0, 0};
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        // 偷cur，那么就不能偷左右节点。
        int val1 = cur->val + left[0] + right[0];
        // 不偷cur，那么可以偷也可以不偷左右节点，则取较大的情况
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return {val2, val1};
    }
};

int main()
{
    std::vector<int> arr{3, 2, 3, -1, 3, -1, 1};
    tree a(arr);
    TreeNode *root = a.root;
    printtree b;
    b.printTree(root);
    traversal(root);
    return 0;
}