#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdio>
#include <set>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <map>
#define ll long long
using namespace std;
const int maxn = 1000;
using namespace std;
const int N = 2010, mod = 1e9 + 7;
int n, m;
ll num[N][N], f[N], inv[N];
ll ans;
ll pow_mod(ll a, ll b, ll c)
{ // 快速幂
    ll ans = 1;
    ll base = a % c;
    while (b)
    {
        if (b & 1)
            ans = (ans * base) % c;
        base = (base * base) % c;
        b >>= 1;
    }
    return ans % c;
}
inline ll C(int k, int n)
{ // 求组合数
    if (k > n)
        return 0;
    return f[n] * inv[k] % mod * inv[n - k] % mod;
}
void init()
{
    // rev2 = pow_mod(2, mod-2,mod);                     // 2的逆元
    f[0] = f[1] = 1;
    for (ll i = 2; i < N; i++)
    { // 预处理阶乘
        f[i] = f[i - 1] * i % mod;
    }

    inv[N - 1] = pow_mod(f[N - 1], mod - 2, mod); // 逆推预处理阶乘的逆元
    for (int i = N - 2; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
    return;
}
int main()
{
    // cin >> n >> m;
    int n = 4;
    int m = 2;
    for (int k = 1; k <= m; k++)
    {
        for (int i = n; i >= 1; i--)
        {
            num[i][k] = (num[i + 1][k] + C(k - 1, n - i + k - 1)) % mod;
        }
    }
    ans = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= m; k++)
        {
            ans = (ans + C(k - 1, i + k - 2) * num[i][k] % mod) % mod;
        }
    }
    cout << ans;
    return 0;
}
