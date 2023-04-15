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

void quit_sort(vector<int> &a, int start, int end)
{
    int i = start;
    int pirot = a[start];
    int j = end;
    while (i < j)
    {
        while (i < j && a[j] >= pirot)
        {
            j--;
        }
        while (i < j && a[i] <= pirot)
        {
            i++;
        }
        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        a[start] = a[i];
        a[i] = pirot;
    }
    quit_sort(a, start, i - 1);
    quit_sort(a, i + 1, end);
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