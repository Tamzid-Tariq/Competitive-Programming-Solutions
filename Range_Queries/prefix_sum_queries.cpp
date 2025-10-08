/*
Problem: Prefix Sum Queries
Link: https://cses.fi/problemset/task/2166/
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

struct node
{
    ll sum, pref, max_sum;
};

struct segtree
{
    ll siz = 1;
    vector<node> val;

    void initialize(ll num)
    {
        while (siz < num)
            siz *= 2;
        val.resize(2 * siz + 1);
    }

    node makenode(ll value)
    {
        node ret;

        ret.pref = max(0LL,value);
        ret.sum = value;
        ret.max_sum = max(0LL, value);

        return ret;
    }

    node merge(node val1, node val2)
    {
        node ret;

        ret.pref = max(val1.pref, val1.sum + val2.pref);
        ret.sum = val1.sum + val2.sum;
        ret.max_sum = max({val1.max_sum, ret.sum, val1.sum + val2.pref});

        return ret;
    }

    void build(vector<ll> &vec, ll parent, ll start, ll end)
    {
        if (end - start == 1)
        {
            if (start < vec.size())
                val[parent] = makenode(vec[start]);
            else
                val[parent] = makenode(0);
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

    void update(ll value, ll ind, ll parent, ll start, ll end)
    {
        if (end - start == 1)
        {
            val[parent] = makenode(value);
            return;
        }

        ll mid = (start + end) / 2;

        if (ind < mid)
            update(value, ind, 2 * parent + 1, start, mid);
        else
            update(value, ind, 2 * parent + 2, mid, end);

        val[parent] = merge(val[2 * parent + 1], val[2 * parent + 2]);
    }

    void update(ll val, ll ind)
    {
        update(val, ind, 0, 0, siz);
    }

    node query(ll lo, ll hi, ll parent, ll start, ll end)
    {
        if (lo <= start && end - 1 <= hi)
            return val[parent];

        if (start > hi || end <= lo)
            return makenode(0);

        ll mid = (start + end) / 2;

        return merge(query(lo, hi, 2 * parent + 1, start, mid), query(lo, hi, 2 * parent + 2, mid, end));
    }

    ll query(ll lo, ll hi)
    {
        return query(lo, hi, 0, 0, siz).max_sum;
    }
};

void solve()
{
    ll num, query;
    cin >> num >> query;

    vector<ll> vec(num);
    for (auto &ot : vec)
        cin >> ot;

    segtree ST;
    ST.initialize(num);
    ST.build(vec);

    while (query--)
    {
        ll op;
        cin >> op;

        if (op == 1)
        {
            ll pos, val;
            cin >> pos >> val;
            pos--;

            ST.update(val, pos);
        }
        else
        {
            ll lo, hi;
            cin >> lo >> hi;
            lo--, hi--;

            cout << ST.query(lo, hi) << endl;
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