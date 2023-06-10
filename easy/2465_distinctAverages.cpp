#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    int distinctAverages(vector<int> &nums)
    {
        set<float> set1;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int m = n / 2;
        for (int i = 0, j = n - 1; i < m; i++, j--)
        {
            float temp = (nums[i] + nums[j]) * 0.5;
            set1.insert(temp);
        }
        return set1.size();
    }
};

int main()
{
    Solution s;
    vector<int> vec = {9, 5, 7, 8, 7, 9, 8, 2, 0, 7};
    int res = s.distinctAverages(vec);
    cout << res;
}