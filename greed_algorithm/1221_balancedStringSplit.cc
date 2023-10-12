#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace std;
class Solution
{
public:
    int balancedStringSplit(string s)
    {
        int result = 0;
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'R')
                count++;
            else
                count--;
            if (count == 0)
                result++;
        }
        return result;
    }
};

int main()
{
    string str = "RLRRLLRLRL";
    Solution s;
    int res = s.balancedStringSplit(str);
    std::cout << res << endl;
    return 0;
}