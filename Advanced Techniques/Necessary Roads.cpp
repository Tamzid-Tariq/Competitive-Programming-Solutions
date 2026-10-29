/*
Problem: Necessary Roads
Link: https://cses.fi/problemset/task/2076/
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
        adj[to].push_back(from);
    }

    vector<ll> start(num, 0), end(num, 0);

    set<pair<ll, ll>> ans;
    ll times = 1;
    function<void(ll, ll)> go = [&](ll node, ll parent)
    {
        end[node] = times;
        start[node] = times++;

        for (auto it : adj[node])
        {
            if (!start[it])
                go(it, node);

            if (it != parent)
                end[node] = min({end[node], end[it]});
        }

        if (parent != -1 && end[node] == start[node])
        {
            ans.insert({min(node, parent), max(node, parent)});
        }
    };

    for (ll i = 0; i < num; i++)
    {
        if (!start[i])
            go(i, -1);
    }

    cout << ans.size() << endl;
    for (auto [it, lit] : ans)
        cout << it + 1 << " " << lit + 1 << endl;
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