#include <iostream>
#include <vector>
using namespace std;
//线段树
class SegmentTree
{
public:
    vector<int> tree; //存放线段树的数字
    int lentree;
    SegmentTree(vector<int> &nums)
    { //用nums来初始化tree数组

        lentree = nums.size(); //记录树中叶节点的长度

        /*初始化4N长度的线段树，默认值是0。 索引从0开始，一个节点i的子节点索引分别是2i+1和2i+2*/
        for (int i = 0; i < 4 * lentree; i++)
            tree.push_back(0);

        buildTree(nums, 0, 0, lentree - 1); //建树函数
    }
    ~SegmentTree() {}

    // tree_index 是节点在线段树的索引。l和r是线段树中任何一个节点的左边界和右边界，当l==r时候表示单个节点
    void buildTree(vector<int> &nums, int tree_index, int l, int r)
    {
        //如果是叶子结点
        if (l > r)
            return;
        if (l == r)
        {
            tree[tree_index] = nums[l];
            return;
        }
        int mid = (l + r) / 2; //将nums数组分成【l, mid】和【mid + 1, r】两段
        //计算左右子节点的索引
        int left = 2 * tree_index + 1;
        int right = 2 * tree_index + 2;

        //分别构建左右子树
        buildTree(nums, left, l, mid);
        buildTree(nums, right, mid + 1, r);

        //这里是用了分治法的思想，建好了左右两个子树然后再计算两者之和，得到整个区间的和
        tree[tree_index] = tree[left] + tree[right];
    }

    //查询的是ql到qr之间的和。l，r表示当前查询的左右边界。tree_index表示当前查询到的节点的编号
    int query(int tree_index, int l, int r, int ql, int qr)
    {

        if ((l == ql) && (r = qr))
        { //已经查询到叶子结点了
            return tree[tree_index];
        }
        int mid = (l + r) / 2;
        int left = 2 * tree_index + 1;
        int right = 2 * tree_index + 2;
        if (qr <= mid)
        { //要查询的部分完全在线段树的左半段
            return query(left, l, mid, ql, qr);
        }
        else if (ql > mid)
        { //要查询的部分完全在线段树的右半段
            return query(right, mid + 1, r, ql, qr);
        }
        else
        { //左右两段都有
            return query(left, l, mid, ql, mid) + query(right, mid + 1, r, mid + 1, qr);
        }
    }

    void update(int tree_index, int l, int r, int index, int val)
    { //更新位于某个叶子结点(索引为index)的值为val
        if (l == r)
        {
            tree[tree_index] = val;
            return;
        }
        int mid = (l + r) / 2;
        int left = 2 * tree_index + 1;
        int right = 2 * tree_index + 2;

        if (index <= mid)
        { //索引index在mid左边，说明在左子树上面
            update(left, l, mid, index, val);
        }
        else
        { //在右子树上面
            update(right, mid + 1, r, index, val);
        }
        //同样用了分治的办法，左右子节点更新完毕之后再更新自己
        tree[tree_index] = tree[left] + tree[right];
    }
    //输出所有叶子结点的值
    void print(int tree_index, int l, int r)
    {
        if (l > r)
            return;
        if (l == r)
        {
            cout << tree[tree_index] << ' ';
            return;
        }
        int mid = (l + r) / 2;
        int left = 2 * tree_index + 1;
        int right = 2 * tree_index + 2;
        print(left, l, mid);
        print(right, mid + 1, r);
    }
};

//外部调用线段树解决问题的类
class NumArray
{
public:
    SegmentTree *segtree;
    NumArray(vector<int> &nums)
    {
        segtree = new SegmentTree(nums);
        segtree->print(0, 0, nums.size() - 1);
        cout << endl;
    }

    void update(int i, int val)
    { //外部调用线段树的更新值函数
        cout << "before update: " << endl;
        segtree->print(0, 0, segtree->lentree - 1);
        cout << "-----------------------------------" << endl;
        segtree->update(0, 0, segtree->lentree - 1, i, val);
        cout << "after update:" << endl;
        segtree->print(0, 0, segtree->lentree - 1);
        cout << "-----------------------------------" << endl;
    }

    int sumRange(int i, int j)
    { //区间求和
        return segtree->query(0, 0, segtree->lentree - 1, i, j);
    }
};

int main()
{
    vector<int> nums = {1, 3, 5};
    NumArray *obj = new NumArray(nums);
    //修改索引1的值为2
    obj->update(1, 2);
    int param_2 = obj->sumRange(0, 2);
    cout << param_2 << endl;
    // system("pause");
    return 0;
}