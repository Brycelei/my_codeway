#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;
        vector<int> temp;
        int n = nums.size();
        int left = 0;
        while (left < n)
        {
            temp.emplace_back(nums[left]);
            while (nums[left] + 1 == nums[left + 1] && left < n - 1)
            {
                cout << left << "\n";
                temp.emplace_back(nums[left + 1]);
                left++;
            }
            if (temp.size() > 1)
            {
                string str1 = to_string(temp[0]) + "->" + to_string(temp.back());
                res.emplace_back(str1);
                temp.clear();
                left++;
            }
            else
            {
                string str = to_string(temp[0]);
                res.emplace_back(str);
                temp.clear();
                left++;
            }
        }
        return res;
    }
};
int main()
{
    vector<int> vec = {0, 1};
    Solution A;
    vector<string> res = A.summaryRanges(vec);
    return 0;
}