/*
Problem: Flight Discount
Link: https://cses.fi/problemset/task/1195/
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
const ll INF = 1e14;

ll vertex, edges, num;
vector<vector<pair<ll, ll>>> adj(100005);
vector<vector<pair<ll, ll>>> readj(100005);
vector<tuple<ll, ll, ll>> connection(200005);

vector<ll> dist;
vector<ll> redist;

void djikstra(bool type)
{

    vector<bool> vis(vertex + 1, false);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,
                   greater<pair<ll, ll>>>
        pq;
    if (type)
    {
        dist.assign(vertex + 1, INF);
        dist[1] = 0;
        pq.push({0, 1});
    }

    else
    {
        redist.assign(vertex + 1, INF);
        redist[vertex] = 0;
        pq.push({0, vertex});
    }

    while (!pq.empty())
    {
        ll node = pq.top().second;
        ll len = pq.top().first;
        pq.pop();
        if ((type) ? (dist[node] < len) : (redist[node] < len))
            continue;
        for (auto child : (type) ? adj[node] : readj[node])
        {
            ll curr = child.first;
            ll cost = child.second;
            if (type ? (dist[curr] > len + cost) : (redist[curr] > len + cost))
            {
                if (type)
                {
                    dist[curr] = len + cost;
                    pq.push({dist[curr], curr});
                }
                else
                {
                    redist[curr] = len + cost;
                    pq.push({redist[curr], curr});
                }
            }
        }
    }
}

void solve()
{
    cin >> vertex >> edges;

    for (ll i = 0; i < edges; i++)
    {
        ll from, to, cost;
        cin >> from >> to >> cost;
        adj[from].push_back({to, cost});
        readj[to].push_back({from, cost});
        connection[i] = make_tuple(from, to, cost);
    }
    djikstra(1);
    djikstra(0);

    ll ans = INF;

    for (ll i = 0; i < edges; i++)
    {
        //cout<<dist[get<0>(connection[i])]<<" "<<redist[get<1>(connection[i])]<<" "<<(get<2>(connection[i]) / 2)<<endl;
        ans = min(ans, dist[get<0>(connection[i])] + redist[get<1>(connection[i])] + (get<2>(connection[i]) / 2));
    }
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