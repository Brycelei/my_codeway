#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findTheLongestBalancedSubstring(string s)
    {
        int n = s.size();
        int i = 0, j = 0;
        int res = 0, cnt = 0;
        while (i < n)
        {
            while (j < n && s[j] == '0')
            {
                j++;
            }
            cnt = j - i;
            i = j;

            while (j < n && s[j] == '1')
            {
                j++;
            }
            res = max(res, min(cnt, j - i) * 2);
            i = j;
        }
        return res;
    }
};

int main()
{
    string str = "01000111";
    Solution s;
    int res = s.findTheLongestBalancedSubstring(str);
    cout << res << "ss";
    return 0;
}