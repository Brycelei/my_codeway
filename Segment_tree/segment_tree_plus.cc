#include <vector>
typedef int hip;
#include <set>
#include <algorithm>
using namespace std;
const hip maxn = hip(1e5 + 9);
#define L t << 1
#define R t << 1 | 1

struct P
{
    hip l, r, m, w, v, f;
} tree[maxn << 2];

vector<hip> orig(maxn);

void push_up(hip t) { tree[t].v = tree[L].v + tree[R].v; }

void push_down(hip t)
{
    if (tree[t].f)
    {
        tree[L].f += tree[t].f;
        tree[R].f += tree[t].f;
        tree[L].v += tree[t].f * tree[L].w;
        tree[R].v += tree[t].f * tree[R].w;
        tree[t].f = 0;
    }
}

void build(hip l, hip r, hip t)
{
    tree[t] = {l, r, (l + r) >> 1, r - l + 1, 0, 0};
    if (l == r)
    {
        tree[t].v = orig[l];
        return;
    }
    build(l, tree[t].m, L);
    build(tree[t].m + 1, r, R);
    push_up(t);
}

void update(hip pl, hip pr, hip n, hip t)
{
    if (pl <= tree[t].l && pr >= tree[t].r)
    {
        tree[t].f += n;
        tree[t].v += n * tree[t].w;
        return;
    }
    push_down(t);
    if (pl <= tree[t].m)
        update(pl, pr, n, L);
    if (pr > tree[t].m)
        update(pl, pr, n, R);
    push_up(t);
}

hip query(hip ql, hip qr, hip t)
{
    if (ql <= tree[t].l && qr >= tree[t].r)
        return tree[t].v;
    push_down(t);
    hip s = 0;
    if (ql <= tree[t].m)
        s += query(ql, qr, L);
    if (qr > tree[t].m)
        s += query(ql, qr, R);
    return s;
}
