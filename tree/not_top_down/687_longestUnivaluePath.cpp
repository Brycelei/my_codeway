// D:\Temp\mycode_way\self_definition\TreeNode.h
#include "../../self_definition/TreeNode.h"
#include <algorithm>
/**
 * @brief question:Given the root of a binary tree, return the length of the longest path,
 * where each node in the path has the same value. This path may or may not pass through the root.
 * The length of the path between two nodes is represented by the number of edges between them.
 * Input: root = [5,4,5,1,1,null,5]
 * Output: 2
 */
class Solution
{
public:
    int len;
    int longestUnivaluePath(TreeNode *root)
    {
        len = 0;
        dfs(root);
        return len;
    }
    //定义dfs为一个节点的左边最大长度，返回值为其左边和右边节点的最大值 return max(left1, right1);
    int dfs(TreeNode *node)
    {
        if (!node)
            return 0;
        // 定义left为左节点的最大长度， right为右节点的的最大长度
        int left = dfs(node->left), right = dfs(node->right);
        int left1 = 0, right1 = 0;
        if (node->left && node->left->val == node->val)
        {
            left1 = left + 1;
        }
        if (node->right && node->right->val == node->val)
        {
            right1 = right + 1;
        }
        // len 定义为全局变量去存储最大长度
        len = std::max(len, left1 + right1);
        return std::max(left1, right1);
    }
};

int main()
{
    std::vector<int> arr{5, 4, 5, 1, 1, 5};
    tree a(arr);
    TreeNode *root = a.root;
    printtree b;
    // b.printTree(root);
    //   traversal(root);
    getchar();
    return 0;
}