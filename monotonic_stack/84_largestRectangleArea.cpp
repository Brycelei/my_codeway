#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        heights.push_back(-1); //同理，我们希望栈中所有数据出栈，所以给数组最后添加一个负数
        stack<int> st;
        int ret = 0, top;
        for (int i = 0; i < heights.size(); i++)
        {
            if (st.empty() || heights[st.top()] <= heights[i])
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && heights[st.top()] > heights[i])
                {
                    top = st.top();
                    st.pop();
                    // i-top指的是当前矩形的宽度，heights[top]就是当前的高度
                    //再次强调栈中现在为单调递增
                    int tmp = (i - top) * heights[top];
                    if (tmp > ret)
                        ret = tmp;
                }
                st.push(top);
                heights[top] = heights[i];
            }
        }
        return ret;
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