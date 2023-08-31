#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxEqualFreq(vector<int> &nums)
    {
        unordered_map<int, int> freq, count;
        int res = 0, maxFreq = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count[nums[i]] > 0)
            {
                freq[count[nums[i]]]--;
            }
            count[nums[i]]++;
            maxFreq = max(maxFreq, count[nums[i]]);
            freq[count[nums[i]]]++;
            /*
                1. 最大次数为 1 则代表当前索引之前所有的数都只出现一次
                2. 除去一个数以外 所有的数出现的频次都相同也就是最大出现次数
                3. 最大出现次数只有一个，且fMap[maxCount -1]满足长度条件,这样macCount去除一位正好退化为maxCount -1
            */

            bool ok = maxFreq == 1 ||
                      freq[maxFreq] * maxFreq + freq[maxFreq - 1] * (maxFreq - 1) == i + 1 && freq[maxFreq] == 1 ||
                      freq[maxFreq] * maxFreq + 1 == i + 1 && freq[1] == 1;
            if (ok)
            {
                res = max(res, i + 1);
            }
        }
        return res;
    }
};
int main()
{
    vector<int> vec = {2, 2, 1, 1, 5, 3, 3, 5};
    Solution s;
    int res = s.maxEqualFreq(vec);
    cout << res << endl;
    return 0;
}