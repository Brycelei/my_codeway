#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// 版本二
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        heights.insert(heights.begin(), 0); // 数组头部加入元素0
        heights.push_back(0);               // 数组尾部加入元素0
        st.push(0);
        int result = 0;
        for (int i = 1; i < heights.size(); i++)
        {
            while (heights[i] < heights[st.top()])
            {
                int mid = st.top();
                st.pop();
                int w = i - st.top() - 1;
                int h = heights[mid];
                result = max(result, w * h);
            }
            st.push(i);
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {2, 1, 5, 6, 2, 3};
    int res = s.largestRectangleArea(vec);
    cout << res;
    return 0;
}