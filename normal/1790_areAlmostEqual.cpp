#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        int n = s1.size();
        if (s1 == s2)
            return true;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
            {
                for (int j = 0; j < n && j != i; j++)
                {
                    swap(s1[i], s1[j]);
                    if (s1 == s2)
                        return true;
                    else
                        swap(s1[j], s1[i]);
                    continue;
                }
            }
        }
        return false;
    }
};

int main()
{
    string s1 = "bank";
    string s2 = "kanb";
    Solution so;
    if (so.areAlmostEqual(s1, s2))
    {
        cout << "可以"
             << "\n";
    }
    else
    {
        cout << "no"
             << "\n";
    }
    return 0;
}