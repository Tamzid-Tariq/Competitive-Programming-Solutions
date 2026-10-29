/*
Problem: Distinct Routes
Link: https://cses.fi/problemset/task/1711/
Author: Tamzid Tariq
Date: 2025-12-02
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
    ll num, edges;
    cin >> num >> edges;

    ll source = 1, sink = num;

    Dinic dinic(sink + 1);

    for (ll i = 1; i <= edges; i++)
    {
        ll road1, road2;
        cin >> road1 >> road2;

        dinic.add_edge(road1, road2, 1);
        // dinic.add_edge(road2, road1, 1);
    }

    ll times = dinic.maxflow(source, sink);
    cout << times << endl;

    vector<ll> visited(2 * edges + 1);

    vector<ll> ans;
    function<bool(ll)> go = [&](ll node)
    {
        // cout<<node<<" visited\n";

        ans.push_back(node);

        if (node == sink)
        {
            cout << ans.size() << "\n";
            for (auto it : ans)
                cout << it << " ";
            cout << endl;

            ans.clear();
            return true;
        }

        for (auto id : dinic.adj[node])
        {
            auto &e = dinic.edges[id];

            // cout << e.from << " -> " << e.to << " == " << e.capacity << " >= " << e.flow << " "<<id<<endl;
            if (e.flow > 0 && !visited[id])
            {
                e.flow = 0;
                visited[id] = 1;
                if (go(e.to))
                    return true;
            }
        }

        return false;
    };
    for (ll j = 0; j < times; j++)
        go(1);
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