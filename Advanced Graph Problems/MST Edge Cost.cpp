/*
Problem: MST Edge Cost
Link: https://cses.fi/problemset/task/3409/
Author: Tamzid Tariq
Date: 2026-07-21
Status: Accepted ✓
*/

#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
#define endl '\n'
const ll modular = 1e9 + 7;
const double pi = acos(-1.0);
const ll INF = 1e18;

struct dsu
{
    vector<ll> parents;
    vector<ll> siz;

    void init(ll len)
    {
        parents.resize(len + 1);
        siz.assign(len + 1, 1);

        for (ll i = 1; i <= len; i++)
            parents[i] = i;
    }

    ll find_par(ll node)
    {
        return parents[node] = ((parents[node] == node || parents[node] == -1) ? (parents[node]) : (find_par(parents[node])));
    }

    void add(ll node1, ll node2)
    {
        ll parent1 = find_par(node1), parent2 = find_par(node2);

        if (siz[parent1] > siz[parent2])
            swap(parent1, parent2);

        siz[parent2] += siz[parent1];
        parents[parent1] = parent2;
    }
};

void solve()
{
    ll num, edges;
    cin >> num >> edges;

    vector<tuple<ll, ll, ll>> all(edges);
    for (auto &[it, lit, kit] : all)
    {
        cin >> it >> lit >> kit;

    }
    vector<ll> good(edges);

    vector<ll> sorted(edges);
    iota(sorted.begin(), sorted.end(), 0);

    sort(sorted.begin(), sorted.end(), [&](ll ind1, ll ind2)
         { return get<2>(all[ind1]) < get<2>(all[ind2]); });

    dsu DSU;
    DSU.init(num + 2);

    vector<vector<pair<ll, ll>>> adj(num + 1);

    ll ans = 0;
    for (ll i = 0; i < edges; i++)
    {
        ll pos = sorted[i];
        auto [x, y, cost] = all[pos];

        if (DSU.find_par(x) == DSU.find_par(y))
            continue;

        DSU.add(x, y);
        ans += cost;
        good[pos] = 1;

        adj[x].push_back({y, cost});
        adj[y].push_back({x, cost});
    }

    vector<ll> depth(num+2);
    vector<vector<ll>> parent(22, vector<ll>(num + 2));
    vector<vector<ll>> maxi(22, vector<ll>(num + 2));

    function<void(ll, ll, ll)> dfs = [&](ll node, ll par, ll deep)
    {
        parent[0][node] = (par == -1 ? 0 : par);
        depth[node] = deep;

        for (ll i = 1; i < 21; i++)
        {
            parent[i][node] = parent[i - 1][parent[i - 1][node]];
            maxi[i][node] = max(maxi[i - 1][node], maxi[i - 1][parent[i - 1][node]]);
        }

        for (auto [it, cost] : adj[node])
        {
            if (it != par)
            {
                maxi[0][it] = cost;
                dfs(it, node, deep + 1);
            }
        }
    };
    dfs(1, 0, 0);

    function<ll(ll, ll)> lca = [&](ll u, ll v)
    {
        if (depth[u] < depth[v])
            swap(u, v);

        ll diff = depth[u] - depth[v];

        for (ll i = 0; i < 21; i++)
        {
            if ((diff >> i) & 1)
                u = parent[i][u];
        }

        if (u == v)
            return u;

        for (ll i = 20; i >= 0; i--)
        {
            if (parent[i][u] != parent[i][v])
            {
                u = parent[i][u];
                v = parent[i][v];
            }
        }

        return parent[0][u];
    };

    function<ll(ll, ll)> got = [&](ll u, ll v)
    {
        ll l = lca(u, v);
        ll du = depth[u] - depth[l];
        ll dv = depth[v] - depth[l];

        // cout << u + 1 << " " << v + 1 << " " << l + 1 << " = " << du << " " << dv << endl;

        ll ret = 0, now = u;
        for (ll i = 0; i < 21; i++)
            if (du & (1LL << i))
            {
                ret = max(ret, maxi[i][now]);
                now = parent[i][now];
            }
        now = v;
        for (ll i = 0; i < 21; i++)
        {
            if (dv & (1LL << i))
            {

                ret = max(ret, maxi[i][now]);
                // cout<<now+1<<" "<<ret<<" -> "<<parent[i][now]+1<<endl;

                now = parent[i][now];
            }
        }
        return ret;
    };

    for (ll i = 0; i < edges; i++)
    {
        auto [u, v, cost] = all[i];
        if (good[i])
        {
            cout << ans << endl;
        }
        else
        {
            cout << ans + cost - got(u, v) << endl;
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