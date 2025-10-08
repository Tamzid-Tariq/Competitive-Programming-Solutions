/*
Problem: Subarray Sum Queries
Link: https://cses.fi/problemset/task/1190/
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

struct segtreeforsubsegmentsum
{
    struct data
    {
        ll sum, pref, suff, ans;
    };

    ll siz = 1;
    vector<data> val;

    data make_data(ll val)
    {
        data res;
        res.sum = val;
        res.pref = res.suff = res.ans = max(0LL, val);
        return res;
    }

    void initialize(ll num)
    {
        while (siz < num)
            siz *= 2;
        val.resize(2 * siz + 1, make_data(0));
    }

    data merge(data l, data r)
    {
        data res;
        res.sum = l.sum + r.sum;
        res.pref = max(l.pref, l.sum + r.pref);
        res.suff = max(r.suff, l.suff + r.sum);
        res.ans = max({l.ans, r.ans, l.suff + r.pref});

        return res;
    }

    void build(vector<ll> &vec, ll parent, ll start, ll end)
    {
        if (end - start == 1)
        {
            if (start < vec.size())
                val[parent] = make_data(vec[start]);
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
            val[parent] = make_data(value);
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

    data query(ll lo, ll hi, ll parent, ll start, ll end)
    {
        if (lo <= start && end - 1 <= hi)
            return val[parent];

        if (start > hi || end <= lo)
            return make_data(0);

        ll mid = (start + end) / 2;

        return merge(query(lo, hi, 2 * parent + 1, start, mid), query(lo, hi, 2 * parent + 2, mid, end));
    }

    ll query(ll lo, ll hi)
    {
        return query(lo, hi, 0, 0, siz).ans;
    }
};

void solve()
{
    ll num, query;
    cin >> num >> query;

    vector<ll> vec(num);
    for (auto &it : vec)
        cin >> it;

    segtreeforsubsegmentsum magicbox;
    magicbox.initialize(num);
    magicbox.build(vec);

    while (query--)
    {

        ll pos, val;
        cin >> pos >> val;
        pos--;

        magicbox.update(val, pos);

        cout<<magicbox.query(0,num-1)<<endl;
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