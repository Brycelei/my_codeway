
// DFS
/**
 * @brief 当输入depth的深度为1的时候，需要创建一个新的root，
 * 当输入 \textit{depth}depth 为 1 时，需要创建一个新的 \textit{root}root，
 * 并将原 \textit{root}root 作为新 \textit{root}root 的左子节点。当 \textit{depth}depth 为 2 时，
 * 需要在 \textit{root}root 下新增两个节点 \textit{left}left 和 \textit{right}right 作为 \textit{root}root 的新子节点，
 * 并把原左子节点作为 \textit{left}left 的左子节点，把原右子节点作为 \textit{right}right 的右子节点。当 \textit{depth}depth 大于 2 时，
 * 需要继续递归往下层搜索，并将 \textit{depth}depth 减去 11，直到搜索到 \textit{depth}depth 为 2。
 *
 *
 */

#include <iostream>
#include <vector>
using namespace std;
#include ".\self_definition\TreeNode.h"
class Solution1
{
public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (!root)
        {
            return nullptr;
        }
        if (depth == 1)
        {
            return new TreeNode(val, root, nullptr);
        }
        if (depth == 2)
        {
            root->left = new TreeNode(val, root->left, nullptr);
            root->right = new TreeNode(val, nullptr, root->right);
        }
        else
        {
            root->left = addOneRow(root->left, val, depth - 1);
            root->right = addOneRow(root->right, val, depth - 1);
        }
        return root;
    }
};

// BFS
/**
 * @brief
 *
 *
 */

class Solution2
{
public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            return new TreeNode(val, root, nullptr);
        }
        vector<TreeNode *> curLevel(1, root);
        for (int i = 1; i < depth - 1; i++)
        {
            vector<TreeNode *> tmpt;
            for (auto &node : curLevel)
            {
                if (node->left != nullptr)
                {
                    tmpt.emplace_back(node->left);
                }
                if (node->right != nullptr)
                {
                    tmpt.emplace_back(node->right);
                }
            }
            curLevel = move(tmpt);
        }
        for (auto &node : curLevel)
        {
            node->left = new TreeNode(val, node->left, nullptr);
            node->right = new TreeNode(val, nullptr, node->right);
        }
        return root;
    }
};
