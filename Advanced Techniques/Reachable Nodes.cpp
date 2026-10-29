/*
Problem: Reachable Nodes
Link: https://cses.fi/problemset/task/2138/
Author: Tamzid Tariq
Date: 2026-02-17
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

// #pragma GCC target("popcnt")

void solve()
{
    ll num, edges;
    cin >> num >> edges;

    vector<vector<ll>> adj(num);

    for (ll i = 0; i < edges; i++)
    {
        ll from, to;
        cin >> from >> to;

        adj[--from].push_back(--to);
    }

    vector<ll> ans(num),visited(num);
    bitset<50000> all[num];

    function<void(ll)> go = [&](ll node)
    {
        visited[node] = 1;
        all[node][node]=1;

        for (auto it : adj[node])
        {
            if (!visited[it])
                go(it);
            all[node] |= all[it];
        }
    };

    for (ll i = 0; i < num; i++)
        if (!visited[i])
            go(i);

    for (ll i = 0; i < num; i++)
        cout << all[i].count() << " ";
    cout << endl;
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