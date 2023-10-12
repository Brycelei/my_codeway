#include <iostream>
#include <vector>
using namespace std;
// 建树
void build_tree(int arr[], int node, int start, int end, vector<int> &tree)
{
    if (start == end)
    {
        tree[node] = arr[start];
    }
    else
    {
        int middle = (start + end) >> 1;
        int left_node = node * 2 + 1;
        int right_node = node * 2 + 2;
        build_tree(arr, left_node, start, middle, tree);
        build_tree(arr, right_node, middle + 1, end, tree);
        tree[node] = tree[left_node] + tree[right_node];
    }
}
// 单点修改
void update_tree(int arr[], vector<int> &tree, int node, int start, int end, int index, int val)
{
    if (start == end)
    {
        arr[index] = val;
        tree[node] = val;
    }
    else
    {
        int middle = (start + end) >> 1;
        int left_node = node * 2 + 1;
        int right_node = node * 2 + 2;
        if (index >= start && index <= middle)
        {
            update_tree(arr, tree, left_node, start, middle, index, val);
        }
        else
        {
            update_tree(arr, tree, right_node, middle + 1, end, index, val);
        }
        tree[node] = tree[left_node] + tree[right_node];
    }
}
// 区间查询
int query_tree(int arr[], vector<int> &tree, int node, int start, int end, int L, int R)
{
    if (R < start || L > end)
    {
        return 0;
    }
    else if (start >= L && end <= R)
    {
        return tree[node];
    }

    int middle = (start + end) >> 1;
    int left_node = 2 * node + 1;
    int right_node = 2 * node + 2;
    int sum_left = query_tree(arr, tree, left_node, start, middle, L, R);
    int sum_right = query_tree(arr, tree, right_node, middle + 1, end, L, R);
    return sum_left + sum_right;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    vector<int> tree(sizeof(arr) / sizeof(int) * 4, 0);
    build_tree(arr, 0, 0, 5, tree);
    cout << tree.size() << endl;
    for (int i = 0; i < 15; ++i)
    {
        cout << tree[i] << " ";
    }
    cout << endl;
    cout << query_tree(arr, tree, 0, 0, 5, 2, 5);
    return 0;
}