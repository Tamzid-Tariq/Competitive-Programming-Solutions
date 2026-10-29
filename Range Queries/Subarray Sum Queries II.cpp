/*
Problem: Subarray Sum Queries II
Link: https://cses.fi/problemset/task/3226/
Author: Tamzid Tariq
Date: 2025-11-25
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

struct node
{
    ll prefmax, suffmax, total, result = 0;
};

struct segtree
{
    ll siz = 1;
    vector<node> val;

    node makenode(ll val)
    {
        node ret;
        ret.prefmax = val;
        ret.suffmax = val;
        ret.total = val;
        ret.result = max(0LL, val);

        return ret;
    }

    void initialize(ll num)
    {
        while (siz < num)
            siz *= 2;
        val.assign(2 * siz + 1, makenode(0));
    }

    node merge(node val1, node val2)
    {
        node ret;

        ret.prefmax = max({val1.prefmax, val1.total + val2.prefmax, val1.total + val2.total});
        ret.suffmax = max({val2.suffmax, val2.total + val1.suffmax, val1.total + val2.total});
        ret.total = val1.total + val2.total;
        ret.result = max({0LL, ret.prefmax, ret.suffmax, ret.total, val1.suffmax + val2.prefmax, val1.result, val2.result});
        return ret;
    }

    void build(vector<ll> &vec, ll parent, ll start, ll end)
    {
        if (end - start == 1)
        {
            if (start < vec.size())
                val[parent] = makenode(vec[start]);
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
        return query(lo, hi, 0, 0, siz).result;
    }
};

void solve()
{
    ll num, queries;
    cin >> num >> queries;

    vector<ll> vec(num);
    for (auto &it : vec)
        cin >> it;

    segtree ST;
    ST.initialize(num);
    ST.build(vec);

    for (ll i = 0; i < queries; i++)
    {
        ll start, end;
        cin >> start >> end;

        cout << ST.query(start - 1, end - 1) << endl;
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