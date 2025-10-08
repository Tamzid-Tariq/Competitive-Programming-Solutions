/*
Problem: Distance Queries
Link: https://cses.fi/problemset/task/1135/
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
const ll INF = 10000000000LL;


vector<vector<ll>> adj;
vector<ll> depth;
vector<vector<ll>> parent;

void dfs(ll node, ll par, ll deep)
{
    parent[0][node] = par;
    depth[node] = deep;

    for (ll i = 1; i < 30; i++)
    {
        parent[i][node] = parent[i - 1][parent[i-1][node]];
    }

    for (auto it : adj[node])
    {
        if (it != par)
        {
            dfs(it, node, deep + 1);
        }
    }
}

ll lca(ll u, ll v)
{
    if (depth[u] < depth[v])
        swap(u, v);

    ll diff = depth[u] - depth[v];

    for (ll i = 0; i < 25; i++)
    {
        if ((diff >> i) & 1)
            u = parent[i][u];
    }

    if (u == v)
        return u;

    for (ll i = 25; i >= 0; i--)
    {
        if (parent[i][u] != parent[i][v])
        {
            u = parent[i][u];
            v = parent[i][v];
        }
    }

    return parent[0][u];
}

ll distance(ll u, ll v)
{
    ll l = lca(u, v);
    ll du = depth[u] - depth[l];
    ll dv = depth[v] - depth[l];
    return du + dv;
}

void solve()
{
    ll num,query;
    cin>>num>>query;

    adj.resize(num);
    parent.resize(30,vector<ll>(num,0LL));
    depth.resize(num,0LL);

    for(ll i=1;i<num;i++)
    {
        ll to,from;
        cin>>to>>from;
        to--,from--;

        adj[to].push_back(from);
        adj[from].push_back(to);
    }

    dfs(0,0,0);

    while(query--)
    {
        ll from,to;
        cin>>from>>to;
        from--,to--;

        cout<<distance(from,to)<<endl;
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