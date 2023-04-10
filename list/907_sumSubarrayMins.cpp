#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> vec;
        // vector<int> tempvec = arr;
        //(4) vector<int> list3(list.begin()+2, list.end()-1); //比较常用
        int res = 0;
        int orgin = 0;
        for (int i = 0; i < n; i++)
        {
            // orgin += arr[i];
            for (int j = i + 1; j <= n; j++)
            {
                vector<int> temp1(arr.begin() + i, arr.begin() + j);
                sort(temp1.begin(), temp1.end());
                res += temp1[0];
                // temp.emplace_back(temp1);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {3, 1, 2, 4};
    int res = s.sumSubarrayMins(vec);
    cout << res;
}