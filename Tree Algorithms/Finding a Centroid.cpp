/*
Problem: Finding a Centroid
Link: https://cses.fi/problemset/task/2079/
Author: Tamzid Tariq
Date: 2025-10-25
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

void solve()
{
    ll num;
    cin >> num;

    vector<vector<ll>> adj(num);
    for (ll i = 0; i < num - 1; i++)
    {
        ll from, to;
        cin >> from >> to;

        adj[--from].push_back(--to);
        adj[to].push_back(from);
    }

    vector<ll> siz(num + 1);

    function<void(ll, ll)> go = [&](ll node, ll par)
    {
        siz[node] = 1;

        for (auto it : adj[node])
        {
            if (it == par)
                continue;

            go(it, node);
            siz[node] += siz[it];
        }
    };

    go(0, -1);

    function<ll(ll, ll)> find_centroid = [&](ll node, ll par)
    {
        for (auto it : adj[node])
        {
            if (it == par)
                continue;
            if (siz[it] > (num / 2))
                return find_centroid(it, node);
        }
        return node;
    };

    cout << find_centroid(0, -1) + 1 << endl;
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