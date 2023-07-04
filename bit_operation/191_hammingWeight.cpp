#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int ret = 0;
        for (int i = 0; i < 32; ++i)
        {
            int b = 1 << i;
            if (n & (1 << i))
            {
                ret++;
            }
        }
        return ret;
    }
};

int main()
{
    int a = 10;
    Solution s;
    int res = s.hammingWeight(a);
    cout << res;
    return 0;
}
