#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <stack>
#include <functional>
#include <unordered_map>
using namespace std;
/*
    同余定理的应用
     如果 pre[j] - pre[i-1] mod k == 0
     只需要 pre[i-1] mod k ==  pre[j] mod k
    */
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> hash;
        int pre = 0;
        hash[0] = 1;
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            pre += nums[i];
            int temp = (pre % k + k) % k; // c++ 负数取余会改变符号
            if (hash.find(temp) != hash.end())
                ans += hash[temp];
            hash[temp]++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {4, 5, 0, -2, -3, 1};
    int k = 5;
    int res = s.subarraysDivByK(vec, k);
    // int a = 10, b = -3;
    // int temp = (a % b + b) % b;
    // cout << temp;

    return 0;
}