#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, pair<int, int>> hash;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                hash[mat[i][j]] = {i, j};
            }
        }
        vector<int> col(n);
        vector<int> row(m);
        int res = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            ++row[hash[arr[i]].first];
            ++col[hash[arr[i]].second];
            if (row[hash[arr[i]].first] == n)
            {
                res = i;
                break;
            }
            if (col[hash[arr[i]].second] == m)
            {
                res = i;
                break;
            }
        }
        return res;
    }
};

/*
1 3 4 2

1 4
2 3

0 1 2 3


二分：

设： 最小下标为 i;

0 1 2 3

0 -> (0,0)
1 -> (1,1)
2- > (0,1)


0-> 0,1
1-> 2,1
2-> 2,2
3-> 1 1



1 4 5 2 6 3

4 3 5
1 2 6
*/

int main()
{
    Solution s;
    vector<int> vec = {1, 4, 5, 2, 6, 3};
    vector<vector<int>> mat = {{4, 3, 5}, {1, 2, 6}};
    int res = s.firstCompleteIndex(vec, mat);
    cout << res;
    return 0;
}