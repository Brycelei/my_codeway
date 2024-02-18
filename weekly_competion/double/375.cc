#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <numeric>
#include <math.h>
using namespace std;
/*
输入：nums = [1,3,4,8,7,9,3,5,1], k = 2
输出：       [[1,1,3],[3,4,5],[7,8,9]]

1,3,4,8,7,9,3,5,1

1 1 3 3 4 5 7 8 9

0 0 2 0 1 1 2 1 0




nums = [1,3,3,2,7,3], k = 3

*/
class Solution1
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i <= n - 3; i += 3)
        {
            vector<int> temp = {nums[i], nums[i + 1], nums[i + 2]};
            if (nums[i + 2] - nums[i] <= k)
            {
                res.emplace_back(temp);
            }
            else
            {
                // break;
                return {};
            }
        }
        return res;
    }
};

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int a = 0, b = 0;
        vector<int> vec(m * n + 1, 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                vec[grid[i][j]]++;
            }
        }
        for (int i = 1; i <= m * n; i++)
        {
            if (vec[i] == 0)
            {
                b = i;
            }
            if (vec[i] == 2)
            {
                a = i;
            }
        }
        return {a, b};
    }
};

class Solution2
{
public:
    long long minimumCost(vector<int> &nums)
    {
        int n = nums.size();
        int min_e = *min_element(nums.begin(), nums.end());
        int max_e = *max_element(nums.begin(), nums.end());
        float pingjun = accumulate(nums.begin(), nums.end(), 0.0);
        float a = pingjun / n;

        int countl = 0;
        int countr = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < a)
            {
                countl++;
            }
            else if (nums[i] > a)
            {
                countr++;
            }
        }
        int temp = countr >= countl ? (int)a + 1 : (int)a;
        // int temp = (int)round(pingjun / n);
        int goleft = 0;
        int goright = 0;
        int templ = temp;
        int tempr = temp;

        while (!ispar(tempr))
        {
            tempr++;
            goright++;
        }
        while (!ispar(templ))
        {
            templ--;
            goleft--;
        }
        temp = goleft > goright ? tempr : templ;
        long long res = 0.0;
        for (int i = 0; i < n; i++)
        {
            res += abs(nums[i] - temp);
        }
        return res;
    }
    bool ispar(int num)
    {
        if (num < 10)
            return true;
        string s = to_string(num);
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            if (s[right] != s[left])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main()
{
    // Solution s;
    // vector<int> nums = {1, 3, 3, 2, 7, 3};

    // //vector<vector<int>> ans = s.divideArray(nums, 2);

    // Solution s;
    // vector<vector<int>> nums = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    // s.findMissingAndRepeatedValues(nums);
    // vector<vector<int>> ans = s.divideArray(nums, 2);

    Solution2 s1;
    vector<int> nums = {22, 33, 22, 33, 22};
    vector<int> nums1 = {301, 309, 312, 322};
    int a = s1.minimumCost(nums1);
    cout << a;
    return 0;
}
