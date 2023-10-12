
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;
struct SegNode
{
    int lo, hi, add;
    SegNode *lchild, *rchild;
    SegNode(int left, int right) : lo(left), hi(right), add(0), lchild(nullptr), rchild(nullptr) {}
};

class Solution
{
public:
    SegNode *build(int left, int right)
    {
        SegNode *node = new SegNode(left, right);
        if (left == right)
        {
            return node;
        }
        int mid = (left + right) / 2;
        node->lchild = build(left, mid);
        node->rchild = build(mid + 1, right);
        return node;
    }

    void insert(SegNode *root, int val)
    {
        root->add++;
        if (root->lo == root->hi)
        {
            return;
        }
        int mid = (root->lo + root->hi) / 2;
        if (val <= mid)
        {
            insert(root->lchild, val);
        }
        else
        {
            insert(root->rchild, val);
        }
    }

    int count(SegNode *root, int left, int right) const
    {
        if (left > root->hi || right < root->lo)
        {
            return 0;
        }
        if (left <= root->lo && root->hi <= right)
        {
            return root->add;
        }
        return count(root->lchild, left, right) + count(root->rchild, left, right);
    }

    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        long long sum = 0;
        vector<long long> preSum = {0};
        for (int v : nums)
        {
            sum += v;
            preSum.push_back(sum);
        }

        set<long long> allNumbers;
        // 存的是各个元素的名次
        for (long long x : preSum)
        {
            allNumbers.insert(x);
            allNumbers.insert(x - lower);
            allNumbers.insert(x - upper);
        }
        // 利用哈希表进行离散化
        unordered_map<long long, int> values;
        int idx = 0;
        for (long long x : allNumbers)
        {
            values[x] = idx;
            idx++;
        }

        SegNode *root = build(0, values.size() - 1);
        int ret = 0;
        for (long long x : preSum)
        {
            int left = values[x - upper], right = values[x - lower];
            ret += count(root, left, right);
            insert(root, values[x]);
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-2, 5, -1};
    int lower = -2, upper = 2;
    s.countRangeSum(nums, -2, 2);
    return 0;
}