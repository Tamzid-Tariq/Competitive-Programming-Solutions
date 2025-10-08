/*
Problem: Road Reparation
Link: https://cses.fi/problemset/task/1675/
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
const ll inf = 1e18;

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
        return ((parents[node] == node || parents[node] == -1) ? (parents[node]) : (find_par(parents[node])));
    }

    bool add(ll node1, ll node2)
    {
        ll parent1 = find_par(node1), parent2 = find_par(node2);

        if (parent1 == parent2)
            return false;

        if (siz[parent1] > siz[parent2])
            swap(parent1, parent2);

        siz[parent2] += siz[parent1];
        parents[parent1] = parent2;
        return true;
    }
};

void solve()
{
    ll num, edges;
    cin >> num >> edges;

    dsu roads;
    roads.init(num);

    vector<tuple<ll, ll, ll>> vec(edges);
    while (edges--)
    {
        ll to, from, cost;
        cin >> to >> from >> cost;
        vec.push_back(make_tuple(cost, to, from));
    }
    sort(vec.begin(), vec.end());

    ll cunt = 1;
    ll ans = 0;
    for (auto it : vec)
    {
        if (roads.add(get<1>(it), get<2>(it)))
        {
            ans += get<0>(it);
            cunt++;
        }
    }
    if (cunt < num)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
        cout << ans << endl;
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