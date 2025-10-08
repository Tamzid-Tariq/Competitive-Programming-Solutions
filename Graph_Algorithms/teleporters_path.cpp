/*
Problem: Teleporters Path
Link: https://cses.fi/problemset/task/1693/
Author: Tamzid Tariq
Date: 2025-10-08
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

const int N = 200005;

ll num, edges;
vector<vector<ll>> adj(N);
vector<ll> circuit;
vector<bool> visited(N);
vector<ll> from(N), to(N), outdegree(N), indegree(N);

void eulerpathdirected(ll start)
{
    vector<ll> path;
    path.push_back(start);

    ll current = start;
    while (!path.empty())
    {
        if (outdegree[current])
        {
            path.push_back(current);
            while (visited[adj[current].back()])
                adj[current].pop_back();

            ll edge = adj[current].back(), next = to[edge];
            visited[edge] = 1;
            outdegree[current]--, indegree[next]--;
            current = next;
        }
        else
        {
            circuit.push_back(current);
            current = path.back();
            path.pop_back();
        }
    }

    reverse(circuit.begin(), circuit.end());
}

void solve()
{
    cin >> num >> edges;

    for (ll i = 0; i < edges; i++)
    {
        ll u, v;
        cin >> u >> v;
        from[i] = --u;
        to[i] = --v;

        adj[u].push_back(i);
        // adj[v].push_back(i);
        outdegree[u]++;
        indegree[v]++;
    }
    bool pos = (outdegree[0] == indegree[0] + 1 && indegree[num - 1] == outdegree[num - 1] + 1);

    for (ll i = 1; i < num - 1; i++)
    {
        if (indegree[i] != outdegree[i])
        {
            pos = 0;
        }
    }
    eulerpathdirected(0);

    if (!pos || circuit.size() != edges + 1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (auto it : circuit)
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