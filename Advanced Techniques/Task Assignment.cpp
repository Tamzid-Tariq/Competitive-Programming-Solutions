/*
Problem: Task Assignment
Link: https://cses.fi/problemset/task/2129/
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

const int N = 1234;
const ll INF = 1e9 + 69;

struct edge
{
    int to, rev_pos;
    ll cap, cost, flow = 0;
};

struct MCMF
{
    int n;
    vector<vector<edge>> E;

    bitset<N> vis;
    int par[N], pos[N];
    ll caps[N], dist[N];

    MCMF(int n) : n(n), E(n) {}

    inline void add_edge(int u, int v, ll cap, ll cost = 0)
    {
        E[u].push_back({v, E[v].size(), cap, cost});
        E[v].push_back({u, E[u].size() - 1, 0, -cost});
    }

    bool SPFA(int S, int T)
    {
        vis.reset();
        for (int i = 0; i < n; ++i)
            caps[i] = dist[i] = INF;
        queue<int> q;
        q.emplace(S), dist[S] = 0, vis[S] = 1;
        while (!q.empty())
        {
            int i = 0, u = q.front();
            q.pop(), vis[u] = 0;
            for (auto &e : E[u])
            {
                int v = e.to;
                ll f = e.cap - e.flow, w = dist[u] + e.cost;
                if (f > 0 and dist[v] > w)
                {
                    dist[v] = w, par[v] = u, pos[v] = i;
                    caps[v] = min(caps[u], f);
                    if (!vis[v])
                        q.push(v), vis[v] = 1;
                }
                ++i;
            }
        }
        return dist[T] != INF;
    }

    pair<ll, ll> GetMaxFlow(int S, int T)
    {
        ll flow = 0, cost = 0;
        while (SPFA(S, T))
        {
            int v = T;
            ll f = caps[v];
            flow += f;
            while (v ^ S)
            {
                int u = par[v];
                edge &e = E[u][pos[v]];
                e.flow += f;
                E[v][e.rev_pos].flow -= f;
                v = u;
            }
            cost += dist[T] * f;
        }
        return make_pair(flow, cost);
    }
};

void solve()
{
    ll num;
    cin >> num;

    MCMF mc(2 * num + 2);

    ll source = 0, sink = 2 * num + 1;

    for (ll i = 1; i <= num; i++)
    {
        mc.add_edge(source, i, 1, 0);
        mc.add_edge(num + i, sink, 1, 0);
    }
    vector<vector<ll>> cost(num + 1, vector<ll>(num + 1));

    for (ll i = 1; i <= num; i++)
    {
        for (ll j = 1; j <= num; j++)
        {
            cin >> cost[i][j];
            mc.add_edge(i, j + num, 1, cost[i][j]);
        }
    }

    auto [flow, got] = mc.GetMaxFlow(source, sink);

    cout << got << endl;

    for (ll i = 1; i <= num; i++)
    {
        for (auto e : mc.E[i])
        {
            if (e.to > num && e.to < sink && e.flow == 1)
            {
                cout << i << " " << e.to - num << endl;
            }
        }
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