#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        vector<vector<string>> res;
        vector<string> path;
        function<void(int i)> dfs = [&](int i)
        {
            if (i == n)
            {
                res.emplace_back(path);
                return;
            }
            for (int j = i; j < n; j++)
            {
                if (isPalindrome1(s, i, j))
                {
                    path.emplace_back(s.substr(i, j - i + 1));
                    dfs(j + 1);
                    path.pop_back();
                }
            }
        };

        dfs(0);
        return res;
    }
    bool isPalindrome(string s, int left, int right)
    {
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
    bool isPalindrome1(string &s, int left, int right)
    {
        while (left < right)
            if (s[left++] != s[right--])
                return false;
        return true;
    }
};

int main()
{
    string str = "aab";
    Solution s;
    vector<vector<string>> ans = s.partition(str);
    for (auto &s : ans)
    {
        for (auto &x : s)
        {
            cout << x << endl;
        }
        cout << "another" << endl;
    }
    return 0;
}