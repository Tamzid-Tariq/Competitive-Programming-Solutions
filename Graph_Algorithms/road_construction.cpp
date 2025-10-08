/*
Problem: Road Construction
Link: https://cses.fi/problemset/task/1676/
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

struct dsu
{
    vector<ll> parents;
    vector<ll> siz;
    ll component;
    ll max_siz;

    void init(ll len)
    {
        parents.resize(len + 1);
        siz.assign(len + 1, 1);

        for (ll i = 1; i <= len; i++)
            parents[i] = i;
        component = len;
        max_siz = 1;
    }

    ll find_par(ll node)
    {
        return ((parents[node] == node || parents[node] == -1) ? (parents[node]) : (find_par(parents[node])));
    }

    void add(ll node1, ll node2)
    {
        ll parent1 = find_par(node1), parent2 = find_par(node2);

        if (parent1 == parent2)
            return;
        component--;
        if (siz[parent1] > siz[parent2])
            swap(parent1, parent2);

        siz[parent2] += siz[parent1];
        max_siz = max(max_siz, siz[parent2]);
        parents[parent1] = parent2;
    }
};

void solve()
{
    ll num, edges;
    cin >> num >> edges;

    struct dsu road;
    road.init(num);

    while (edges--)
    {
        ll to, from;
        cin >> to >> from;

        road.add(to, from);
        cout << road.component << " " << road.max_siz << endl;
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