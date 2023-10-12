#include <functional>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

string stemp;
void dfs(vector<char> &vec, vector<string> &res, vector<bool> &isused)
{
    int n = vec.size();
    if (stemp.size() == n)
    {
        res.emplace_back(stemp);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isused[i] == true)
            continue;
        isused[i] = true;
        stemp += vec[i];
        dfs(vec, res, isused);
        stemp.pop_back();
        isused[i] = false;
    }
}

vector<string> getall(string &str)
{
    int n = str.size();
    vector<char> vec;
    for (auto s : str)
    {
        vec.emplace_back(s);
    }
    vector<string> res;
    vector<bool> isused(n, false);
    dfs(vec, res, isused);
    return res;
}
int main()
{
    int n;
    cin >> n;
    string str;
    string sibling;
    int sortnumber;
    vector<string> vec;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        vec.emplace_back(str);
    }
    cin >> sibling;
    cin >> sortnumber;
    vector<string> stringset = getall(sibling);
    unordered_set<string> uset(stringset.begin(), stringset.end());
    vector<string> restring;
    for (int i = 0; i < n; i++)
    {
        if (uset.count(vec[i]) && vec[i] != sibling)
        {
            res++;
            restring.emplace_back(vec[i]);
        }
    }
    sort(restring.begin(), restring.end());
    cout << res << endl;
    cout << restring[sortnumber - 1];

    // getall(str);
    return 0;
}