#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        int len1 = s.size();
        int len2 = a.size();
        int len3 = b.size();
        vector<int> res;
        vector<int> temp;
        int index = 0;
        while ((index = s.find(a, index)) < s.length())
        {
            temp.emplace_back(index);
            index++;
        }
        int index1 = 0;
        vector<int> temp1;
        while ((index1 = s.find(b, index1)) < s.length() && index1 >= 0)
        {

            temp1.emplace_back(index1);
            index1++;
        }

        for (int i = 0; i < temp.size(); i++)
        {
            for (int j = 0; j < temp1.size(); j++)
            {
                if (abs(temp[i] - temp[j]) <= k)
                {
                    res.emplace_back(temp[i]);
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution so;
    string s = "dexgscgecd";
    string a = "gscge";
    string b = "d";
    vector<int> res = so.beautifulIndices(s, a, b, 6);
    for (auto &x : res)
    {
        cout << x << endl;
    }
    return 0;
}
