#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
// C++
class Solution
{
public:
    int alternateDigitSum(int n)
    {
        int res = 0;
        vector<int> vec;
        while (n > 0)
        {
            int temp = n % 10;

            n = n / 10;
            cout << n;
            vec.emplace_back(temp);
        }
        reverse(vec.begin(), vec.end());
        for (int i = 0; i < vec.size(); i++)
        {
            if (i % 2 == 0)
            {
                res += vec[i];
            }
            else
            {
                res -= vec[i];
            }
        }
        return res;
    }
};

int main()
{
    int in = 521;
    class Solution A;
    A.alternateDigitSum(in);
    return 0;
}