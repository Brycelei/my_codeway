#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution
{
public:
    int rotatedDigits(int n)
    {
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            string num = to_string(i);
            bool valid = true, diff = false;
            for (char ch : num)
            {
                if (check[ch - '0'] == -1)
                {
                    valid = false;
                }
                else if (check[ch - '0'] == 1)
                {
                    diff = true;
                }
            }
            if (valid && diff)
            {
                ++ans;
            }
        }
        return ans;
    }

private:
    static constexpr int check[10] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};
};
/**
 * @brief 根据题目的要求，一个数是好数，当且仅当：
 * 数中没有出现 3, 4, 73,4,7；
 * 数中至少出现一次 22 或 55 或 66 或 99；
 * 对于 0, 1, 80,1,8 则没有要求。
 */
int main()
{
    vector<int> vec = {5, 7, 1, 4};
    Solution s;
    int res = s.rotatedDigits(10);
    return 0;
}