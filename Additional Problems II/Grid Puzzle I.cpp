/*
Problem: Grid Puzzle I
Link: https://cses.fi/problemset/task/2432/
Author: Tamzid Tariq
Date: 2026-08-31
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

struct edge
{
    int to, from;
    ll capacity, flow;

    edge() {}

    edge(int from, int to, ll capacity) : to(to), from(from), capacity(capacity), flow(0) {}
};

struct Dinic
{
    int num_nodes;
    vector<vector<int>> adj;
    vector<edge> edges;
    vector<int> level;
    vector<int> ptr;

    Dinic(int n) : num_nodes(n), adj(n), level(n), ptr(n) {}

    void add_edge(int from, int to, ll capacity)
    {
        if (from ^ to)
        {
            adj[from].push_back(edges.size());
            edges.push_back(edge(from, to, capacity));
            adj[to].push_back(edges.size());
            edges.push_back(edge(to, from, 0)); // Residual edge
        }
    }

    bool bfs(int s, int t)
    {
        level.assign(num_nodes, num_nodes + 1);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            if (node == t)
                break;

            for (int id : adj[node])
            {
                auto &e = edges[id];
                if (e.capacity > e.flow && level[e.to] > level[e.from] + 1)
                {
                    level[e.to] = level[e.from] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] != num_nodes + 1;
    }

    ll dfs(int node, int t, ll flow = -1)
    {
        if (node == t || flow == 0)
            return flow;

        for (int &i = ptr[node]; i < adj[node].size(); i++)
        {
            edge &e = edges[adj[node][i]];
            edge &oe = edges[adj[node][i] ^ 1];

            if (level[e.to] == level[e.from] + 1)
            {
                ll amt = e.capacity - e.flow;

                if (flow != -1 && amt > flow)
                    amt = flow;

                if (ll pushed = dfs(e.to, t, amt))
                {
                    e.flow += pushed;
                    oe.flow -= pushed;
                    return pushed;
                }
            }
        }
        return 0LL;
    }

    ll maxflow(int s, int t)
    {
        ll total = 0;

        while (bfs(s, t))
        {
            fill(ptr.begin(), ptr.end(), 0);

            while (ll flow = dfs(s, t))
                total += flow;
        }

        return total;
    }

    vector<pair<int, int>> min_cut(int s, int t)
    {
        maxflow(s, t);
        vector<bool> visited(num_nodes);
        queue<int> q;
        q.push(s);
        visited[s] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (int id : adj[node])
            {
                if (edges[id].capacity - edges[id].flow > 0 && !visited[edges[id].to])
                {
                    visited[edges[id].to] = true;
                    q.push(edges[id].to);
                }
            }
        }

        vector<pair<int, int>> cut_edges;
        for (const auto &e : edges)
        {
            if (visited[e.from] && !visited[e.to] && e.capacity > 0)
            {
                cut_edges.push_back({e.from, e.to});
            }
        }

        return cut_edges;
    }
};

void solve()
{
    ll num;
    cin >> num;

    vector<ll> row(num + 1), col(num + 1);

    for (ll i = 1; i <= num; i++)
        cin >> row[i];

    for (ll i = 1; i <= num; i++)
        cin >> col[i];

    ll totalr = accumulate(row.begin(), row.end(), 0LL), totalc = accumulate(col.begin(), col.end(), 0LL);

    if (totalr != totalc)
    {
        cout << -1 << endl;
        return;
    }

    Dinic din(2 * num + 2);

    ll source = 0, sink = 2 * num + 1;
    for (ll i = 1; i <= num; i++)
    {
        din.add_edge(source, i, row[i]);
        din.add_edge(num + i, sink, col[i]);
    }

    for (ll i = 1; i <= num; i++)
    {
        for (ll j = num + 1; j <= 2 * num; j++)
            din.add_edge(i, j, 1);
    }

    if (din.maxflow(source, sink) != totalc)
    {
        cout << -1 << endl;
        return;
    }

    vector<vector<char>> ans(num, vector<char>(num, '.'));

    for (auto e : din.edges)
    {
        if (e.from >= 1 && e.from <= num && e.to > num && e.to <= 2 * num && e.flow == 1)
        {
            ans[e.from - 1][e.to - num - 1] = 'X';
        }
    }
    for (ll i = 0; i < num; i++)
    {
        for (ll j = 0; j < num; j++)
            cout << ans[i][j];

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