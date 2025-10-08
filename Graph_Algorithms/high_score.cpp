/*
Problem: High Score
Link: https://cses.fi/problemset/task/1673/
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

ll vertex, edge;
vector<vector<pair<ll, ll>>> adj(2505);
vector<ll> dist(2505, -10000000000LL);
vector<bool> visited(2505, false);

void dfs(ll x)
{
    visited[x] = true;

    for (auto it : adj[x])
    {
        if (!visited[it.first])
            dfs(it.first);
    }
}

bool visited1[2505];

void dfs1(ll x)
{
    visited1[x] = true;

    for (auto it : adj[x])
    {
        if (!visited1[it.first])
            dfs1(it.first);
    }
}



void solve()
{
    cin >> vertex >> edge;

    for (ll i = 0; i < edge; i++)
    {
        ll from, to, cost;
        cin >> from >> to >> cost;

        adj[from].push_back({to, cost});
    }

    // if(edge>(vertex)*(vertex+1)/2)
    // {
    //     cout<<-1<<endl;
    //     return;
    // }

    dist[1] = 0;
    for (ll times = 1; times < vertex; times++)
    {
        for (ll node = 1; node <= vertex; node++)
        {
            for (auto it : adj[node])
            {
                if (it.second + dist[node] > dist[it.first])
                {
                    dist[it.first] = it.second + dist[node];
                }
            }
        }
    }
    ll ans = dist[vertex];

    vector<ll> cycle;
    for (ll node = 1; node <= vertex; node++)
    {
        for (auto it : adj[node])
        {
            if (it.second + dist[node] > dist[it.first])
            {
                dist[it.first] = it.second + dist[node];
                cycle.push_back(it.first);
            }
        }
    }

    ll siz = cycle.size();
    dfs(1);
    for (ll i = 0; i < siz; i++)
    {
        //cout<<cycle[i]<<" ";
        dfs1(cycle[i]);
        if ((visited[cycle[i]] || visited1[1]) && (visited1[vertex]))
        {
                cout << -1 << endl;
                return;
            
            
        }memset(visited1, false, sizeof visited1);
    }

    cout << dist[vertex] << endl;
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