#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
/**
 * Definition for a binary tree node.
 **/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * @brief 二叉树的生成与输出
 * std::vector中值为-1表示为空节点
 */
class tree
{ //二叉树生成
public:
    TreeNode *root;
    tree(std::vector<int> &arr)
    { //建树
        int len = arr.size();
        std::queue<TreeNode *> bfsque;
        root = new TreeNode(arr[0]);
        bfsque.push(root);
        int i = 0;
        while (bfsque.size())
        {
            if (++i >= len)
                break;
            auto node = bfsque.front();
            bfsque.pop();
            if (arr[i] != -1)
            {
                node->left = new TreeNode(arr[i]);
                bfsque.push(node->left);
            }
            if (++i >= len)
                break;
            if (arr[i] != -1)
            {
                node->right = new TreeNode(arr[i]);
                bfsque.push(node->right);
            }
        }
    }
    ~tree()
    {
        std::stack<TreeNode *> sta;
        sta.push(root);
        while (sta.size())
        {
            auto tmp = sta.top();
            sta.pop();
            auto left = tmp->left;
            auto right = tmp->right;
            delete tmp;
            if (right)
                sta.push(right);
            if (left)
                sta.push(left);
        }
    }
};

class printtree
{ //格式化输出
public:
    std::vector<std::vector<std::string>> res;
    std::vector<std::vector<std::string>> printTree(TreeNode *root)
    { //格式化输出
        int dep = depth(root);
        int len = pow(2, dep) - 1;
        res = std::vector<std::vector<std::string>>(dep, std::vector<std::string>(len, "   "));
        helper(root, 0, 0, len - 1);
        for (int i = 0; i < dep; i++)
        {
            for (int j = 0; j < len; j++)
                std::cout << res[i][j] << " ";
            std::cout << "\n";
        }
        return res;
    }
    int depth(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + std::max(depth(root->left), depth(root->right));
    }
    void helper(TreeNode *root, int depth, int left, int right)
    {
        if (!root)
            return;
        int index = (left + right) / 2;
        char s[4];
        sprintf(s, "%-3d", root->val);
        res[depth][index] = std::string(s);
        helper(root->left, depth + 1, left, index - 1);
        helper(root->right, depth + 1, index + 1, right);
    }
};
void traversal(TreeNode *root)
{ //非格式化输出
    std::queue<TreeNode *> bfs;
    bfs.push(root);
    bool notblankline = true;
    while (notblankline && !bfs.empty())
    {
        int size = bfs.size();
        notblankline = false;
        while (size--)
        {
            auto tmp = bfs.front();
            bfs.pop();
            if (!tmp)
            {
                std::cout << "null ";
                continue;
            }
            std::cout << tmp->val << " ";
            bfs.push(tmp->left);
            bfs.push(tmp->right);
            if (tmp->left || tmp->right)
                notblankline = true;
        }
        std::cout << "\n";
    }
}
