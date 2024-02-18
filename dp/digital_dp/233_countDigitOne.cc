#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <algorithm>
#include <string.h>
#include <functional>
using namespace std;
class Solution
{
public:
    int countDigitOne(int n)
    {
        auto s = to_string(n);
        int m = s.size();
        int dp[m][m];
        memset(dp, -1, sizeof(dp));
        function<int(int, int, bool)> f = [&](int i, int cnt1, bool islimit) -> int
        {
            if (i == m)
                return cnt1;
            if (!islimit && dp[i][cnt1] >= 0)
                return dp[i][cnt1];
            int res = 0;
            int up = islimit ? s[i] - '0' : 9;
            for (int d = 0; d <= up; d++)
            {
                res += f(i + 1, cnt1 + (d == 1), islimit && d == up);
            }
            if (!islimit)
                dp[i][cnt1] = res;
            return res;
        };
        return f(0, 0, true);
    }
};

/*
https://blog.csdn.net/weixin_45532984/article/details/129697570?ops_request_misc=&request_id=&biz_id=102&utm_term=%E6%95%B0%E4%BD%8Ddp&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-7-129697570.142^v99^pc_search_result_base3&spm=1018.2226.3001.4187
在什么情况下才可以使用备忘录呢？此时对于记忆化方程f(x)来说，我们需要记录走到了第几位，也需要知道当前1的个数，此时的x为集合{i，cntOne}，i是来到第几位，cntOne是1的个数，有了这两个部分才能进行缓存，记忆化方程变为f(i,cntOne).
*/
int main()
{
    Solution s;
    int res = s.countDigitOne(13);
    cout << res;
    return 0;
}
