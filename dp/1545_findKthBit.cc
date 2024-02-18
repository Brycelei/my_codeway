#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    char findKthBit(int n, int k)
    {
        function<string(string)> opp = [&](string s) -> string
        {
            string temp;
            for (int i = 0; i < s.size(); i++)
            {

                char c = (char)('0' + '1' - s[i]); // 如果为1，那么就剩下0，如果为1，就是0，不能通过取反操作去做
                temp += c;
            }
            reverse(temp.begin(), temp.end());
            return temp;
        };
        vector<string> dp(n + 1);
        dp[0] = '0';
        for (int i = 1; i < n + 1; i++)
        {
            dp[i] = dp[i - 1] + "1" + opp(dp[i - 1]);
        }
        return dp[n][k - 1];
    }
};

int main()
{
    Solution s;
    char c = s.findKthBit(3, 1);
    return 0;
}