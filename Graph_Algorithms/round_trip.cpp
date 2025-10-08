/*
Problem: Round Trip
Link: https://cses.fi/problemset/task/1669/
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

ll vertex;
vector<ll> adjacent[200006];
vector<bool> visited(200006);
vector<ll> parent(200006);
ll cycle_start, cycle_end;

bool dfs(ll node, ll par)
{
    visited[node] = true;
    for (int child : adjacent[node])
    {
        if (child == par)
            continue;
        if (visited[child])
        {
            cycle_end = node;
            cycle_start = child;
            return true;
        }
        parent[child] = node;
        if (dfs(child, parent[child]))
            return true;
    }
    return false;
}

void find_cycle()
{
    visited.assign(vertex, false);
    parent.assign(vertex, -1);
    cycle_start = -1;

    for (int start = 1; start <= vertex; start++)
    {
        if (!visited[start] && dfs(start, parent[start]))
            break;
    }
    if (cycle_start == -1)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        cout << cycle.size() << endl;
        for (int printing : cycle)
            cout << printing << " ";
        cout << endl;
    }
    return;
}

void solve()
{
    ll connect;
    cin >> vertex >> connect;

    for (ll i = 0; i < connect; i++)
    {
        ll a, b;
        cin >> a >> b;
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }
    find_cycle();
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