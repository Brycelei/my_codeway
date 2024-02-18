#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <numeric>
using namespace std;
class Solution
{
public:
    bool areSimilar(vector<vector<int>> &mat, int k)
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> temp(mat);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i % 2 == 0)
                {
                    vector<int> even = temp[i];
                    even.insert(even.end(), temp[i].begin(), temp[i].end());

                    vector<int> b(even.begin() + n - k % n, even.begin() + n - k % n + n);
                    temp[i] = b;
                }
                else
                {
                    vector<int> odd = temp[i];
                    odd.insert(odd.end(), temp[i].begin(), temp[i].end());
                    vector<int> c(odd.begin() + k % n, odd.begin() + n + k % n);
                    temp[i] = c;
                }
            }
        }
        if (temp == mat)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class Solution1
{
public:
    unordered_set<char> uset{'a', 'e', 'i', 'o', 'u'};

    int beautifulSubstrings(string s, int k)
    {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= n - i; j++)
            {
                string temp = s.substr(i, j);
                if (temp.size() % 2 == 1)
                {
                    continue;
                }
                if (isbitufule(temp, k))
                {
                    res++;
                }
            }
        }
        return res;
    }
    bool isbitufule(string s, int k)
    {
        int n = s.size();
        int cons = 0, vow = 0;
        for (int i = 0; i < n; i++)
        {
            if (uset.count(s[i]))
            {
                vow++;
            }
            else
            {
                cons++;
            }
        }
        if (vow == 0 || cons == 0)
            return false;

        if ((vow * cons) % k == 0)

        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    // Solution s;
    // vector<vector<int>> mat = {{1, 2, 1, 2}, {5, 5, 5, 5}, {6, 3, 6, 3}};
    // bool res = s.areSimilar(mat, 2);
    // cout << res;

    Solution1 s;
    string s1 = "uzuxpzou";

    int res = s.beautifulSubstrings(s1, 3);
    cout << res;
    return 0;
}
