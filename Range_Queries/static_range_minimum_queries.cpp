/*
Problem: Static Range Minimum Queries
Link: https://cses.fi/problemset/task/1647/
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

struct sparsetable
{
    vector<vector<ll>> lookup;
    vector<ll> arr;
    ll times = 1, siz;

    void initialize(ll num)
    {
        siz = num;
        arr.resize(num);
        times = log2(num);
        lookup.resize(num, vector<ll>(times + 1));
    }

    ll merge(ll val1, ll val2)
    {
        return min(val1, val2);
    }

    void build(vector<ll> &vec)
    {
        for (ll i = 0; i < siz; i++)
            lookup[i][0] = vec[i];

        for (ll j = 1; j <= times; j++)
        {
            for (ll i = 0; i + (1LL << j) <= siz; i++)
                lookup[i][j] = merge(lookup[i][j - 1], lookup[i + (1LL << (j - 1))][j - 1]);
        }
    }

    ll query(ll lo, ll hi)
    {
        ll j = log2(hi - lo + 1);

        return merge(lookup[lo][j], lookup[hi - (1LL << j) + 1][j]);
    }
};

void solve()
{
    ll num, query;
    cin >> num >> query;

    vector<ll> vec(num);
    for (auto &ot : vec)
        cin >> ot;

    sparsetable ST;
    ST.initialize(num);
    ST.build(vec);

    while (query--)
    {
        ll lo, hi;
        cin >> lo >> hi;

        lo--, hi--;

        cout << ST.query(lo, hi) << endl;
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