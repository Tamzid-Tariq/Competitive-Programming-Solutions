/*
Problem: Range Update Queries
Link: https://cses.fi/problemset/task/1651/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
const ll modular = 1e9 + 7;
const double pi = acos(-1.0);
const ll INF = 10000000000LL;

struct lazysegtree
{
    ll siz = 1;
    vector<ll> val;
    vector<ll> lazy;

    void initialize(ll num)
    {
        while (siz < num)
            siz *= 2;
        val.assign(2 * siz + 1, 0);
        lazy.assign(2 * siz + 1, 0);
    }

    ll merge(ll val1, ll val2)
    {
        return (val1 + val2);
    }

    void build(vector<ll> &vec, ll parent, ll start, ll end)
    {
        if (end - start == 1)
        {
            if (start < vec.size())
                val[parent] = vec[start];
            return;
        }

        ll mid = (start + end) / 2;

        build(vec, 2 * parent + 1, start, mid);
        build(vec, 2 * parent + 2, mid, end);

        val[parent] = merge(val[2 * parent + 1], val[2 * parent + 2]);
    }

    void build(vector<ll> &vec)
    {
        build(vec, 0, 0, siz);
    }

    void update(ll value, ll lo, ll hi, ll parent, ll start, ll end)
    {
        if (lo <= start && end - 1 <= hi)
        {
            lazy[parent] += value;
            return;
        }

        if (start > hi || end <= lo)
            return;

        ll mid = (start + end) / 2;

        update(value, lo, hi, 2 * parent + 1, start, mid);
        update(value, lo, hi, 2 * parent + 2, mid, end);
    }

    void update(ll val, ll lo, ll hi)
    {
        update(val, lo, hi, 0, 0, siz);
    }

    ll query(ll ind, ll parent, ll start, ll end)
    {
        if (lazy[parent])
        {
            val[parent] += lazy[parent] * (end - start);

            if (end - start > 1)
            {
                lazy[2 * parent + 1] += lazy[parent];
                lazy[2 * parent + 2] += lazy[parent];
            }
            lazy[parent] = 0;
        }
        if (end - start == 1)
            return val[parent];

        ll mid = (start + end) / 2;

        if (ind < mid)
            return query(ind, 2 * parent + 1, start, mid);
        else
            return query(ind, 2 * parent + 2, mid, end);
    }

    ll query(ll ind)
    {
        return query(ind, 0, 0, siz);
    }
};

void solve()
{
    ll num, query;
    cin >> num >> query;

    vector<ll> vec(num);
    for (auto &it : vec)
        cin >> it;

    lazysegtree ST;
    ST.initialize(num + 1);
    ST.build(vec);

    while (query--)
    {
        ll type;
        cin >> type;

        if (type == 1)
        {
            ll lo, hi, value;
            cin >> lo >> hi >> value;
            lo--, hi--;

            ST.update(value, lo, hi);
        }

        else
        {
            ll value;
            cin >> value;
            cout << ST.query(value - 1) << endl;
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