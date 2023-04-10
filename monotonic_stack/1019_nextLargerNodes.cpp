#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> res;
        stack<pair<int, int>> sta;
        for (ListNode *i = head; i != nullptr; i = i->next)
        {
            while (!sta.empty() && i->val > sta.top().first)
            {
                res[sta.top().second] = i->val;
                sta.pop();
            }
            sta.emplace(i->val, res.size());
            res.emplace_back(0);
        }
        return res;
    }
};