/*
Problem: Necessary Cities
Link: https://cses.fi/problemset/task/2077/
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

    vector<ll> start(num, 0), low(num, INF);

    set<ll> ans;
    ll times = 1;
    function<void(ll, ll)> go = [&](ll node, ll parent)
    {
        start[node] = low[node] = times++;

        ll child = 0;

        for (auto it : adj[node])
        {
            if (it == parent)
                continue;

            if (!start[it])
            {
                go(it, node);

                low[node] = min(low[node], low[it]);

                child++;
                if (node && low[it] >= start[node])
                {
                    ans.insert(node);
                }
            }
            else
            {
                low[node] = min(low[node], start[it]);
            }
        }

        if (!node && child >= 2)
            ans.insert(0);
    };

    go(0, -1);

    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it + 1 << " ";
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