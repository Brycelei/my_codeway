#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int sumDistance(vector<int> &nums, string s, int d)
    {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> a(n); // 用 long long 是因为 nums[i]+d 可能是 2e9+1e9，溢出了
        for (int i = 0; i < n; i++)
            a[i] = (long long)nums[i] + d * ((s[i] & 2) - 1); // L=-1, R=1
        sort(a.begin(), a.end());

        long long ans = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            ans = (ans + i * a[i] - sum) % MOD;
            sum += a[i];
        }
        return ans;
    }
};

/*
[-2,0,2]
[1,-1,-1]

[-1,]

(a[i]−a[0])+(a[i]−a[1])+⋯+(a[i]−a[i−1])  = i⋅a[i]−(a[0]+a[1]+⋯+a[i−1])

​
 pos[j](前缀和)
*/
int main()
{
    vector<int> vec = {-2, 0, 2};
    string str = "RLL";
    Solution s;
    int res = s.sumDistance(vec, str, 3);
    return 0;
}