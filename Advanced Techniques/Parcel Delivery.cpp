/*
Problem: Parcel Delivery
Link: https://cses.fi/problemset/task/2121/
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
const ll INF = 1e18;

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
    ll num, edges, need;
    cin >> num >> edges >> need;

    MCMF mc(num + 2);

    ll source = 1, sink = num + 1;

    mc.add_edge(num, sink, need, 0);

    for (ll i = 0; i < edges; i++)
    {
        ll from, to, flow, cost;
        cin >> from >> to >> flow >> cost;

        mc.add_edge(from, to, min(flow, need), cost);
    }

    auto [flow, got] = mc.GetMaxFlow(source, sink);

    if (flow != need)
    {
        cout << -1 << endl;
        return;
    }
    // cout << flow<<" "<<got << endl;

    cout << got << endl;

    ll ans = 0;
    for (ll i = 1; i < num; i++)
    {
        for (auto e : mc.E[i])
        {

            // cout<<i<<" -> "<<e.to<<" => "<<e.flow<<endl;

            if (e.flow > 0)
            {
                ans += e.flow * e.cost;
            }
        }
    }
    assert(ans == got);
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