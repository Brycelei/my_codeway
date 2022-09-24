#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();
        vector<int> res(n);
        if (k == 0)
        {
            return res;
        }
        code.resize(n * 2);
        copy(code.begin(), code.begin() + n, code.begin() + n); //直接分配2倍长度的vector
        int l = k > 0 ? 1 : n + k;
        int r = k > 0 ? k : n - 1;
        int w = 0;
        for (int i = l; i <= r; i++)
        {
            w += code[i];
        }
        for (int i = 0; i < n; i++)
        {
            res[i] = w;
            w -= code[l];
            w += code[r + 1];
            l++;
            r++;
        }
        return res;
    }
};

int main()
{
    vector<int> vec = {5, 7, 1, 4};
    Solution s;
    vector<int> res = s.decrypt(vec, 3);
    // cout << res << endl;
    for (auto &x : res)
    {
        cout << x << "\n";
    }
    return 0;
}