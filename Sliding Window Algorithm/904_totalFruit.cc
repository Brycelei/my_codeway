#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        int left = 0, right = 0;
        unordered_map<int, int> window;
        int res = 0;
        while (right < n)
        {
            window[fruits[right]]++;
            right++;
            while (window.size() > 2 && left <= right)
            {
                window[fruits[left]]--;
                if (window[fruits[left]] == 0)
                    window.erase(fruits[left]);
                left++;
            }
            res = max(res, right - left);
        }
        return res;
    }
};

/*


1 2 1

0 1 2 2

1 2 3 2 2

窗口里面是什么？
是水果种类，[1,2]

unordered_set<int>



*/
int main()
{
    vector<int> vec = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    vector<int> vec1 = {1, 2, 3, 2, 2};

    Solution s;
    int res = s.totalFruit(vec1);
    cout << res;

    return 0;
}