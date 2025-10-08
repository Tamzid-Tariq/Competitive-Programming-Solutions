/*
Problem: Distinct Values Queries
Link: https://cses.fi/problemset/task/1734/
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
const ll INF = 1e18;

struct segtree
{
    ll siz = 1;
    vector<ll> val;

    void initialize(ll num)
    {
        while (siz < num)
            siz *= 2;
        val.assign(2 * siz + 1, 0);
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

    void update(ll value, ll ind, ll parent, ll start, ll end)
    {
        if (end - start == 1)
        {
            val[parent] = value;
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

    ll query(ll lo, ll hi, ll parent, ll start, ll end)
    {
        if (lo <= start && end - 1 <= hi)
            return val[parent];

        if (start > hi || end <= lo)
            return 0;

        ll mid = (start + end) / 2;

        return merge(query(lo, hi, 2 * parent + 1, start, mid), query(lo, hi, 2 * parent + 2, mid, end));
    }

    ll query(ll lo, ll hi)
    {
        return query(lo, hi, 0, 0, siz);
    }
};

void solve()
{
    ll num, queries;
    cin >> num >> queries;

    vector<ll> vec(num);

    segtree ST;
    ST.initialize(num);

    for (auto &it : vec)
    {
        cin >> it;
    }

    vector<tuple<ll, ll, ll>> q(queries);

    for (ll i = 0; i < queries; i++)
    {
        ll start, end;
        cin >> start >> end;

        start--, end--;

        q[i] = {end, start, i};
    }
    sort(q.begin(), q.end());

    vector<ll> ans(queries);

    map<ll, ll> lastseen;

    ll next = get<0>(q[0]), ind = 0;

    for (ll i = 0; i < num; i++)
    {
        if (lastseen.count(vec[i]))
        {
            ST.update(0, lastseen[vec[i]]);
        }
        lastseen[vec[i]] = i;
        ST.update(1, i);

        while (next == i)
        {
            auto [end, begin, index] = q[ind];

            ans[index] = ST.query(begin, end);
            ind++;
            if (ind >= queries)
                next = num + 1;
            else
                next = get<0>(q[ind]);
        }
    }

    for (auto it : ans)
        cout << it << endl;
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