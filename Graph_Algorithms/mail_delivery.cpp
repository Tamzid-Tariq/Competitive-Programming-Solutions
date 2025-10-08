/*
Problem: Mail Delivery
Link: https://cses.fi/problemset/task/1691/
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
vector<ll> from(N), to(N), degree(N);

void eulerpathundirected(ll start)
{
    vector<ll> path;
    path.push_back(start);

    ll current = start;
    while (!path.empty())
    {
        if (degree[current])
        {
            path.push_back(current);
            while (visited[adj[current].back()])
                adj[current].pop_back();

            ll edge = adj[current].back(), next = current ^ from[edge] ^ to[edge];
            visited[edge] = 1;
            degree[current]--, degree[next]--;
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
        adj[v].push_back(i);
        degree[u]++;
        degree[v]++;
    }
    bool pos = 1, wrong = 0;

    for (ll i = 0; i < num; i++)
    {
        if (degree[i] & 1)
        {
            if (wrong)
                pos = 0;
            else
                wrong = 1;
        }
    }
    eulerpathundirected(0);

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