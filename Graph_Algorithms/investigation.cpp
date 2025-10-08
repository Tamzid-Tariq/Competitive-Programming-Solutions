/*
Problem: Investigation
Link: https://cses.fi/problemset/task/1202/
Author: Tamzid Tariq
Date: 2025-10-08
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

void solve()
{
    ll num, edges;
    cin >> num >> edges;

    vector<vector<pair<ll, ll>>> adj(num);

    for (ll i = 0; i < edges; i++)
    {
        ll to, from, cost;
        cin >> to >> from >> cost;

        to--, from--;
        adj[to].push_back({from, cost});
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    vector<tuple<ll, ll, ll, ll>> dist(num, {INF, 1, INF, LLONG_MIN});
    pq.push({0, 0});
    dist[0] = {0, 1, 0, 0};

    while (!pq.empty())
    {
        auto [cost, node] = pq.top();
        pq.pop();

        auto [nodedist, nodetimes, nodemiini, nodemaxi] = dist[node];

        if (nodedist < cost)
            continue;

        for (auto [next, price] : adj[node])
        {
            auto &[nextdist, nexttimes, nextmini, nextmaxi] = dist[next];

            if (nextdist == price + cost)
            {
                nextmini = min(nextmini, nodemiini + 1);
                nextmaxi = max(nextmaxi, nodemaxi + 1);
                nexttimes += nodetimes;
                nexttimes %= modular;
            }

            if (nextdist > price + cost)
            {

                dist[next] = {price + cost, nodetimes, nodemiini + 1, nodemaxi + 1};
                pq.push({price + cost, next});
            }
        }
    }

    auto [minidist, times, miniflights, maxiflights] = dist[num - 1];
    cout << minidist << " " << times << " " << miniflights << " " << maxiflights << endl;
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