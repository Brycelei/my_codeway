#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int n = blocks.size();
        int nums = 0;
        for (int i = 0, j = i + k; i <= n - k && j < n; i++, j++)
        {
            int black = 0;
            int white = 0;
            int left = i, right = j;
            while (left < right)
            {
                if (blocks[left] == 'W')
                {
                    white++;
                }
                else
                {
                    black++;
                }
                left++;
            }
            nums = max(nums, black);
            if (black > k)
                return 0;
            cout << i << endl
                 << j << endl;
            cout << black << "sss" << endl;
        }
        return k - nums;
    }
};

/*
|W B B W W B B| W B W

0     3 4

w 3
b 4

W |B B W W B B W| B W

w 3
b 4

W B |B W W B B W B| W

w 3
b 4

W B B| W W B B W B W|

w = 4
b = 3


*/

int main()
{
    Solution s;
    string s1 = "BWWWBB";
    int k = 6;
    int res = s.minimumRecolors(s1, k);
    cout << res;
}