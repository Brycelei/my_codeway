#include <iostream>
#include <vector>
using namespace std;

int biarysearch(vector<int> &vec, int left, int right, int target)
{
    if (left >= right)
    {
        return -1;
    }
    int middle = (left + right) >> 1;
    if (vec[middle] < target)
    {
        return biarysearch(vec, middle + 1, right, target);
    }
    else if (vec[middle] > target)
    {
        return biarysearch(vec, left, middle, target);
    }
    else
    {
        return middle;
    }
}

int main()
{
    vector<int> vec = {1, 2, 3, 5, 7};
    int res = biarysearch(vec, 0, vec.size(), 2);
    cout << res;
    return 0;
}