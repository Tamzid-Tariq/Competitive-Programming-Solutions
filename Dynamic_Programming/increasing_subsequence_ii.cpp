/*
Problem: Increasing Subsequence II
Link: https://cses.fi/problemset/task/1748/
Author: Tamzid Tariq
Date: 2025-10-08
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll modularBinaryExponentiation(ll base, ll exponent)
{
    if (exponent == 0)
        return 1;

    ll result = modularBinaryExponentiation(base, exponent / 2);
    result %= modular;

    if (exponent & 1)
        return (((((result * result)) % modular) * base) % modular);
    else
        return ((result * result) % modular);
}

ll add(ll val1, ll val2)
{
    ll result = (val1 % modular) + (val2 % modular);
    return result % modular;
}

ll subtract(ll val1, ll val2)
{
    ll result = modular + ((val1 % modular) - (val2 % modular));
    return result % modular;
}

ll multiply(ll val1, ll val2)
{
    ll result = (val1 % modular) * (val2 % modular);
    return result % modular;
}

ll divide(ll val1, ll val2)
{
    ll denominator = modularBinaryExponentiation(val2 % modular, modular - 2) % modular;
    ll result = multiply(val1, denominator);

    return result % modular;
}

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
    ll num;
    cin >> num;

    map<ll, ll> mp;
    set<ll> s;

    vector<ll> vec(num);
    for (auto &it : vec)
    {
        cin >> it;
        s.insert(it);
    }

    while (!s.empty())
    {
        mp[*s.rbegin()] = s.size();
        s.erase(*s.rbegin());
    }

    for (auto &it : vec)
        it = mp[it];

    vector<ll> got(*max_element(vec.begin(), vec.end()) + 1);

    segtree ST;
    ST.initialize(*max_element(vec.begin(), vec.end()) + 1);

    ll result = 0;
    for (ll i = 0; i < num; i++)
    {
        ll now = ST.query(0, vec[i] - 1);
        result = add(result, now + 1);

        got[vec[i]] = add(got[vec[i]], now + 1);
        ST.update(got[vec[i]], vec[i]);
    }

    cout << result << endl;
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