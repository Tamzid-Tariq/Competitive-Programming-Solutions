/*
Problem: Download Speed
Link: https://cses.fi/problemset/task/1694/
Author: Tamzid Tariq
Date: 2025-12-01
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
        if(node==t || flow==0) return flow;

        for(int &i=ptr[node];i<adj[node].size();i++)
        {
            edge &e=edges[adj[node][i]];
            edge &oe= edges[adj[node][i]^1];
            
            if(level[e.to]==level[e.from]+1)
            {
                ll amt = e.capacity - e.flow;

                if(flow!=-1 && amt>flow)amt = flow;

                if(ll pushed = dfs(e.to,t,amt))
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
        ll total=0;

        while(bfs(s,t))
        {
            fill(ptr.begin(),ptr.end(),0);

            while(ll flow = dfs(s,t))total+=flow;
        }

        return total;
    }
};

void solve()
{
    ll num, edges;
    cin >> num >> edges;

    Dinic dinic(num);
    for (ll i = 0; i < edges; i++)
    {
        ll from, to, capacity;
        cin >> from >> to >> capacity;

        dinic.add_edge(--from, --to, capacity);
    }

    cout << dinic.maxflow(0, num - 1) << endl;
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