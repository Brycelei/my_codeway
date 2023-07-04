#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createList(vector<int> &nums)
{
    ListNode *h = new ListNode(-1);
    ListNode *t;
    t = h;

    for (int i = 0; i < nums.size(); ++i)
    {
        t->next = new ListNode(nums[i]);
        t = t->next;
    }
    return h->next;
}

void print_list(ListNode *head)
{
    while (head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        if (!head)
            return nullptr;
        ListNode *Next = removeZeroSumSublists(head->next);
        head->next = Next;
        return dfs(head);
    }
    ListNode *dfs(ListNode *head)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        int res = 0;
        while (head)
        {
            // cout<<head->val;
            res = res + head->val;
            // cout << res;
            if (res == 0)
            {
                dummy->next = head->next;
                break;
            }
            head = head->next;
        }
        return dummy->next;
    }
};

int main()
{
    Solution s;
    vector<int> a1{1, 2, 3, -3, 4};
    ListNode *l1 = createList(a1);

    ListNode *res = s.removeZeroSumSublists(l1);
    print_list(res);

    return 0;
}
