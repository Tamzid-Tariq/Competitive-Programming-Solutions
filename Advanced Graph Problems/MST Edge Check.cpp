/*
Problem: MST Edge Check
Link: https://cses.fi/problemset/task/3407/
Author: Tamzid Tariq
Date: 2026-08-19
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

    map<ll, vector<ll>> mp;
    vector<tuple<ll, ll, ll>> vec(edges);
    for (ll i = 0; i < edges; i++)
    {
        auto &[it, lit, kit] = vec[i];
        cin >> it >> lit >> kit;

        it--, lit--;

        mp[kit].push_back(i);
    }

    dsu DSU;
    DSU.init(num);

    vector<ll> ans(edges);

    for (auto [it, lit] : mp)
    {
        for (auto ind : lit)
        {
            auto [node1, node2, cost] = vec[ind];
            ans[ind] = (DSU.find_par(node1) != DSU.find_par(node2));
        }

        for (auto ind : lit)
        {
            auto [node1, node2, cost] = vec[ind];
            DSU.add(node1, node2);
        }
    }
    for (auto it : ans)
        cout << (it ? "YES\n" : "NO\n");
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