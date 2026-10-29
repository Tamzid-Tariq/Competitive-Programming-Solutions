/*
Problem: Range Queries and Copies
Link: https://cses.fi/problemset/task/1737/
Author: Tamzid Tariq
Date: 2025-11-23
Status: Accepted ✓
*/

#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
#define endl '\n';
const ll modular = 1e9 + 7;
const double pi = acos(-1.0);
const ll INF = 1e18;

ll merge(ll a, ll b)
{
    return (ll)a + (ll)b;
}

struct Vertex
{
    Vertex *l, *r;
    ll result;

    Vertex(int val) : l(nullptr), r(nullptr), result(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), result(0LL)
    {
        if (l)
            result = merge(result, l->result);
        if (r)
            result = merge(result, r->result);
    }
};

Vertex *build(int a[], int tl, int tr)
{
    if (tl == tr)
        return new Vertex(a[tl]);
    int tm = (tl + tr) / 2;
    return new Vertex(build(a, tl, tm), build(a, tm + 1, tr));
}

ll query(Vertex *v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0LL;
    if (l == tl && tr == r)
        return v->result;
    int tm = (tl + tr) / 2;
    return merge(query(v->l, tl, tm, l, min(r, tm)), query(v->r, tm + 1, tr, max(l, tm + 1), r));
}

Vertex *update(Vertex *v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
        return new Vertex(new_val);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm + 1, tr, pos, new_val));
}

void solve()
{
    ll num, queries;
    cin >> num >> queries;

    int vec[num + 1];
    vec[0] = 0;

    for (int i = 1; i <= num; i++)
    {
        cin >> vec[i];
    }

    int tl = 0, tr = num;
    std::vector<Vertex *> roots;
    roots.push_back(build(vec, tl, tr));

    for (int i = 0; i < queries; i++)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int who, where, val;
            cin >> who >> where >> val;
            --who;

            roots[who] = update(roots[who], tl, tr, where, val);
        }
        else if (type == 2)
        {
            int who, start, end;
            cin >> who >> start >> end;
            --who;

            cout << query(roots[who], tl, tr, start, end) << endl;
        }
        else
        {
            int who;
            cin >> who;
            --who;
            roots.push_back(update(roots[who], tl, tr, 0, 0));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    n = 1;
    // cin >> n;
    for (ll i = 1; i <= n; ++i)
    {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}