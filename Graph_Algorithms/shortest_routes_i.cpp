/*
Problem: Shortest Routes I
Link: https://cses.fi/problemset/task/1671/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int;
using ull = unsigned long long int;
using namespace std;
const ll modular = 1e9 + 7;
const double pi = 22 / 7;
const ll INF = 1000000000000000000;

ll vertex;
vector<pair<ll, ll>> adj[1000006];
vector<ll> dist;

void djikstra()
{
    dist.assign(vertex + 1, INF);

    dist[1] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        ll len = pq.top().first;
        ll curr = pq.top().second;
        pq.pop();
        if (dist[curr] < len)
            continue;
        for (auto child : adj[curr])
        {
            ll node = child.first;
            ll cost = child.second;

            if (dist[node] > len + cost)
            {
                dist[node] = len + cost;

                pq.push({dist[node], node});
            }
        }
    }
}

void solve()
{
    ll edges;
    cin >> vertex >> edges;
    for (ll i = 0; i < edges; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        // adj[b].push_back({a, c});
    }

    djikstra();
    for (ll i = 1; i <= vertex; i++)
        cout << dist[i] << " ";
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