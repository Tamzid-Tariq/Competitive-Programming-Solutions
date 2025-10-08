/*
Problem: Cycle Finding
Link: https://cses.fi/problemset/task/1197/
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

struct Edge
{
    ll from, to, cost;
};

ll vertex, edges;       // no. of vertex and edges in the graph
vector<Edge> vec(5090); // store the edges from,to and cost.
vector<ll> dist(5090);
vector<ll> parent(5090, -1);

void find_negative_cycle(vector<ll> &path)
{
    // run this after bellman ford has been run
    ll start = -1;
    for (ll i = 1; i < max(2LL,vertex); i++)
    {
        start = -1;
        for (Edge it : vec)
        {

            if (dist[it.from] + it.cost < dist[it.to])
            {
                dist[it.to] = dist[it.from] + it.cost;
                start = it.to;
                parent[it.to] = it.from;
            }
        }
    }

    if (start == -1)
        return; // no Negative cycle found so, path is empty

    for (ll times = 0; times < vertex; times++)
        start = parent[start];

    path.push_back(start);
    for (ll current = parent[start];; current = parent[current])
    {
        path.push_back(current);
        if (current == start)
            break;
    }
    reverse(path.begin(), path.end());
}

void solve()
{
    cin >> vertex >> edges;

    for (ll i = 0; i < edges; i++)
    {
        cin >> vec[i].from >> vec[i].to >> vec[i].cost;
    }

    vector<ll> cycle;
    find_negative_cycle(cycle);
    if (cycle.empty())
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        for (auto it : cycle)
            cout << it << " ";
        cout << endl;
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