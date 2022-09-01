#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            int pr = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (prices[j] <= prices[i])
                {
                    pr = prices[i] - prices[j];
                    res.emplace_back(pr);
                    break;
                }
                if (j == n - 1)
                {
                    pr = prices[i];
                    res.emplace_back(pr);
                }
            }
            if (i == n - 1)
            {
                res.emplace_back(prices[i]);
            }
        }
        return res;
    }
};
int main()
{
    vector<int> prices = {8, 4, 6, 2, 3};
    vector<int> popped = {4, 5, 3, 2, 1};
    class Solution A;
    A.finalPrices(prices);
    return 0;
}