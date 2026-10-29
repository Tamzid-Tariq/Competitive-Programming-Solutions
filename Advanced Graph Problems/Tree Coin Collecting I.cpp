/*
Problem: Tree Coin Collecting I
Link: https://cses.fi/problemset/task/3114/
Author: Tamzid Tariq
Date: 2026-10-27
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
    ll num, queries;
    cin >> num >> queries;

    vector<ll> good(num);
    for (auto &it : good)
        cin >> it;

    vector<vector<ll>> adj(num);
    for (ll i = 1; i < num; i++)
    {
        ll from, to;
        cin >> from >> to;

        adj[--from].push_back(--to);
        adj[to].push_back(from);
    }

    vector<ll> depth(num);
    vector<vector<ll>> parent(20, vector<ll>(num));

    function<void(ll, ll, ll)> dfs = [&](ll node, ll par, ll deep)
    {
        parent[0][node] = par;
        depth[node] = deep;

        for (ll i = 1; i < 20; i++)
        {
            parent[i][node] = parent[i - 1][parent[i - 1][node]];
        }

        for (auto it : adj[node])
        {
            if (it != par)
            {
                dfs(it, node, deep + 1);
            }
        }
    };

    dfs(0, 0, 0);

    function<ll(ll, ll)> lca = [&](ll u, ll v)
    {
        if (depth[u] < depth[v])
            swap(u, v);

        ll diff = depth[u] - depth[v];

        for (ll i = 0; i < 20; i++)
        {
            if ((diff >> i) & 1)
                u = parent[i][u];
        }

        if (u == v)
            return u;

        for (ll i = 19; i >= 0; i--)
        {
            if (parent[i][u] != parent[i][v])
            {
                u = parent[i][u];
                v = parent[i][v];
            }
        }

        return parent[0][u];
    };

    vector<vector<ll>> dist(21, vector<ll>(num, INF));
    queue<ll> q;
    for (ll i = 0; i < num; i++)
    {
        if (good[i])
        {
            dist[0][i] = 0;
            q.push(i);
        }
    }

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (dist[0][it] > dist[0][node] + 1)
            {
                dist[0][it] = 1 + dist[0][node];
                q.push(it);
            }
        }
    }

    for (ll i = 1; i < 21; i++)
    {
        for (ll j = 0; j < num; j++)
        {
            dist[i][j] = min(dist[i - 1][j], dist[i - 1][parent[i - 1][j]]);
        }
    }

    function<ll(ll,ll)>distance=[&](ll u, ll v)
    {
        ll l = lca(u, v);
        ll du = depth[u] - depth[l];
        ll mini = min(dist[0][v], dist[0][u]);
        u = parent[0][u];
        for (ll j = 0; j < 21; j++)
        {
            if ((du) & (1LL << j))
            {
                mini = min(mini, dist[j][u]);
                u = parent[j][u];
            }
        }
        ll dv = depth[v] - depth[l];
        v = parent[0][v];
        for (ll j = 0; j < 21; j++)
        {
            if ((dv) & (1LL << j))
            {
                mini = min(mini, dist[j][v]);
                v = parent[j][v];
            }
        }
        return du + dv +2*mini;
    };

    for(ll i=0;i<queries;i++)
    {
        ll node1,node2;
        cin>>node1>>node2;

        cout<<distance(node1-1,node2-1)<<endl;
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