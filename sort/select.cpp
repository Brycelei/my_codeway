#include <iostream>
#include <vector>
using namespace std;

void select(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int minnum = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minnum])
            {
                minnum = j;
            }
        }
        if (minnum != i)
        {
            std::swap(a[i], a[minnum]);
        }
    }
}

int main()
{

    vector<int> a = {1, 3, 4, 6};

    select(a);
    for (auto &x : a)
    {
        std::cout << x << "\n";
    }
    return 0;
}