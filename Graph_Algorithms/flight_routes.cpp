/*
Problem: Flight Routes
Link: https://cses.fi/problemset/task/1196/
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
const ll INF = 1000000000000000000LL;

void solve()
{
    ll num, edges, times;
    cin >> num >> edges >> times;

    vector<vector<pair<ll, ll>>> adj(num);

    for (ll i = 0; i < edges; i++)
    {
        ll to, from, cost;
        cin >> to >> from >> cost;
        to--, from--;
        adj[to].push_back({from, cost});
    }

    vector<ll> visited(num, 0);
    vector<multiset<ll>> dist(num);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 0});
    dist[0].insert(0);

    while (!pq.empty())
    {
        auto [dis,node]=pq.top();      pq.pop();

        if(dist[num-1].size()>=times && *dist[node].rbegin()<dis)continue;

        for(auto [next,cost]:adj[node])
        {
            if(dist[next].size()<times)
            {
                pq.push({dis+cost,next});
                dist[next].insert(dis+cost);
            }
            else if(*dist[next].rbegin() > (dis+cost))
            {
                dist[next].erase(dist[next].find(*dist[next].rbegin()));
                dist[next].insert(dis+cost);
                pq.push({dis+cost,next});
            }
        }
    }

    for (auto it : dist[num - 1])
    {
        times--;
        cout << it << " ";
        if (!times)
            return;
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