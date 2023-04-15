#include <iostream>
#include <stack>
#include <vector>
#include <climits>
#include <stack>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = prices[0];
        int sold = 0;
        for (auto &x : prices)
        {
            sold = max(sold, x - buy);
            buy = min(buy, x);
        }
        return sold;
    }
    int maxProfit_monostack(vector<int> &prices)
    {
        int res = 0;
        int n = prices.size();
        prices.emplace_back(0);
        vector<int> sta;
        for (int i = n - 1; i > 0; --i)
        {
            while (!sta.empty() && prices[i] > sta.back())
            {
                int maxsold = std::max(res, sta.back() - sta.front());
                sta.pop_back();
            }
            sta.emplace_back(prices[i]);
        }
        return res;
    }
};

int main()
{
    vector<int> vec{7, 1, 5, 3, 6, 4};
    Solution A;
    int result = A.maxProfit(vec);
    cout << result;
    return 0;
}
