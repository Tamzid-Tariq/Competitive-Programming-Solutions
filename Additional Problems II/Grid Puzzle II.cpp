/*
Problem: Grid Puzzle II
Link: https://cses.fi/problemset/task/2131/
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
// const ll INF = 1e18;

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

    MCMF din(2 * num + 2);

    ll source = 0, sink = 2 * num + 1;
    for (ll i = 1; i <= num; i++)
    {
        din.add_edge(source, i, row[i], 0);
        din.add_edge(num + i, sink, col[i], 0);
    }

    vector<vector<ll>> cost(num + 1, vector<ll>(num + 1));
    for (ll i = 1; i <= num; i++)
    {
        for (ll j = num + 1; j <= 2 * num; j++)
        {
            cin >> cost[i][j - num];
            din.add_edge(i, j, 1, -cost[i][j - num]);
        }
    }

    auto [flow, wt] = din.GetMaxFlow(source, sink);

    if (flow != totalc)
    {
        cout << -1 << endl;
        return;
    }

    cout << abs(wt) << endl;

    vector<vector<char>> ans(num, vector<char>(num, '.'));

    for (ll i = 1; i <= num; i++)
        for (auto e : din.E[i])
        {
            if (e.to > num && e.to <= 2 * num && e.flow == 1)
            {
                ans[i - 1][e.to - num - 1] = 'X';
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