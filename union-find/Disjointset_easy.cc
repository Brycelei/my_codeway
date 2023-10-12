#include <iostream>
#include <vector>
using namespace std;

class disjoinset
{
    vector<int> parent;
    // int max_size;
    disjoinset(int max_size) : parent(vector<int>(max_size))
    {
        for (int i = 0; i < max_size; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if (x == parent[x])
            return x;
        return find(parent[x]);
    }
    void to_union(int x, int y)
    {
        parent[find(x)] = find(y);
    }
    bool isconnet(int x, int y)
    {
        return find(x) == find(y);
    }
};