#include <iostream>
#include <vector>
using namespace std;
void insert(vector<int> &nums)
{
    int n = nums.size();
    int i, j;
    for (int i = 1; i < n; i++)
    {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}
int main()
{
    vector<int> nums = {1, 3, 2, 4, 5};
    insert(nums);
    for (auto &x : nums)
    {
        cout << x << endl;
    }
    return 0;
}