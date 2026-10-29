/*
Problem: Graph Girth
Link: https://cses.fi/problemset/task/1707/
Author: Tamzid Tariq
Date: 2026-08-18
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
    for (ll i = 1; i <= edges; i++)
    {
        ll from, to;
        cin >> from >> to;

        adj[--from].push_back(--to);
        adj[to].push_back(from);
    }

    ll ans = INF;

    queue<ll> q;
    for (ll i = 0; i < num; i++)
    {
        vector<ll> when(num, -1);

        when[i] = 0;
        q.push(i);

        while (!q.empty())
        {
            ll node = q.front();
            q.pop();

            for (auto it : adj[node])
            {
                if (when[it] >= when[node])
                {
                    ans = min(ans, when[it] + when[node] + 1);
                }
                else if (when[it] == -1)
                {
                    when[it] = when[node] + 1;
                    q.push(it);
                }
            }
        }
    }

    cout << (ans == INF ? -1 : ans) << endl;
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