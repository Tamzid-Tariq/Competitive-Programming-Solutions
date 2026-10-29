/*
Problem: Counting Paths
Link: https://cses.fi/problemset/task/1136/
Author: Tamzid Tariq
Date: 2025-10-26
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

const ll N = 200005;

vector<vector<ll>> adj(N);
vector<ll> depth(N);
vector<vector<ll>> parent(30, vector<ll>(N));

void dfs(ll node, ll par, ll deep)
{
    parent[0][node] = par;
    depth[node] = deep;

    for (ll i = 1; i < 30; i++)
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
    int num, query;
    cin >> num >> query;

    // vector<vector<int>>adj(num);
    for (ll i = 1; i < num; i++)
    {
        ll from, to;
        cin >> from >> to;

        adj[--from].push_back(--to);
        adj[to].push_back(from);
    }

    vector<ll> ans(num), ended(num);

    function<void(ll, ll)> go = [&](ll node, ll par)
    {
        for (auto it : adj[node])
        {
            if (it == par)
                continue;

            go(it, node);
            ans[node] += ans[it] - ended[it];
        }
        ans[node] -= ended[node];
    };

    dfs(0, 0, 0);

    for (ll i = 0; i < query; i++)
    {
        ll from, to;
        cin >> from >> to;

        from--, to--;

        // cout<<from+1<<" "<<to+1<<" -> "<<1+lca(from,to)<<endl;
        ans[from]++;
        ans[to]++;

        ended[lca(from, to)]++;
    }

    go(0, -1);

    for (auto it : ans)
        cout << it << " ";
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