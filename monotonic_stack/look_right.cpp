#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

int peopleNumber(vector<int> &heights)
{
    heights.push_back(INT_MAX);
    int result = 0;
    stack<int> st;

    for (int i = 0; i < heights.size(); ++i)
    {
        // 单调递增栈，遇大则出栈
        while (!st.empty() && heights[st.top()] < heights[i])
        {
            result += (i - st.top() - 1);
            st.pop();
        }
        st.push(i);
    }
    return result;
}

/**
 * @brief n个人站队，所有人向右看，个子高的可以看到个子矮的人的头顶；给出每个人的身高，
 * 问所有人能看到其他人的头顶数量的总和是多少。
 * [4,3,7,1]
 * 4能看到3，7能看到1
 * @return int
 */
int main()
{
    vector<int> vec{4, 3, 7, 1};
    int result = peopleNumber(vec);
    cout << "result = " << result << endl;
    return 0;
}
