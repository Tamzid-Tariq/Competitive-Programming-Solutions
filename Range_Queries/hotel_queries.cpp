/*
Problem: Hotel Queries
Link: https://cses.fi/problemset/task/1143/
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

struct segtree
{
    ll siz = 1;
    // vector<ll> val;
    vector<pair<ll, ll>> val;

    void initialize(ll num)
    {
        while (siz < num)
            siz *= 2;
        val.assign(2 * siz + 1, {0, 0});
    }

    // ll merge(ll val1, ll val2)
    // {
    //     return max(val1,val2);
    // }

    pair<ll, ll> merge(pair<ll, ll> val1, pair<ll, ll> val2)
    {
        if (val1.first > val2.first || (val1.first == val2.first && val1.second < val2.second))
            return val1;

        return val2;
    }

    void build(vector<ll> &vec, ll parent, ll start, ll end)
    {
        if (end - start == 1)
        {
            if (start < vec.size())
                val[parent] = {vec[start], start};
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
            val[parent].first = value;
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

    pair<ll, ll> query(ll lo, ll hi, ll parent, ll start, ll end)
    {
        if (lo <= start && end - 1 <= hi)
            return val[parent];

        if (start > hi || end <= lo)
            return {0, 0};

        ll mid = (start + end) / 2;

        return merge(query(lo, hi, 2 * parent + 1, start, mid), query(lo, hi, 2 * parent + 2, mid, end));
    }

    pair<ll, ll> query(ll lo, ll hi)
    {
        return query(lo, hi, 0, 0, siz);
    }
};

void solve()
{
    ll num1, num2;
    cin >> num1 >> num2;

    vector<ll> vec(num1);

    for (auto &it : vec)
        cin >> it;

    segtree sg;
    sg.initialize(num1);
    sg.build(vec);

    while (num2--)
    {
        ll need;
        cin >> need;

        ll lo = 0, hi = num1;
        auto [maxi, ind] = sg.query(lo, hi);
        if (maxi < need)
        {
            cout << 0 << " ";
            continue;
        }
        ll ans = 0;

        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            auto [maxi, ind] = sg.query(lo, mid);
            if (maxi >= need)
            {
                ans = ind + 1;
                hi = mid - 1;
                // cout<<ind+1<<" ";
                // break;
            }
            else
            {
                lo = mid + 1;
            }
        }
        if (vec[ans - 1] >= need)
        {
            cout << ans << " ";
            vec[ans - 1] -= need;
            sg.update(vec[ans - 1], ans - 1);
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