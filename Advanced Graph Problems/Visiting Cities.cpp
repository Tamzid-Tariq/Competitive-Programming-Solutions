/*
Problem: Visiting Cities
Link: https://cses.fi/problemset/task/1203/
Author: Tamzid Tariq
Date: 2026-08-24
Status: Accepted ✓
*/

#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
#define endl '\n';

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distrib((ll)1e9, (ll)2e9);
const ll modular = distrib(rng);
const ll modular2 = distrib(rng);

const double pi = acos(-1.0);
const ll INF = 1e18;

const ll N = 200005;
vector<pair<ll, ll>> adj[2][N];

void solve()
{
    ll num, edges;
    cin >> num >> edges;

    for (ll i = 0; i < edges; i++)
    {
        ll from, to, cost;
        cin >> from >> to >> cost;

        adj[0][--from].push_back({--to, cost});
        adj[1][to].push_back({from, cost});
    }

    vector<vector<ll>> dist(2, vector<ll>(num, INF)), ways(2, vector<ll>(num, 0));
    vector<vector<ll>> dist2(2, vector<ll>(num, INF)), ways2(2, vector<ll>(num, 0));

    function<void(ll, ll)> go = [&](ll start, ll type)
    {
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0, start});
        dist[type][start] = 0;
        ways[type][start] = 1;

        dist2[type][start] = 0;
        ways2[type][start] = 1;

        while (!pq.empty())
        {
            auto [cost, node] = pq.top();
            pq.pop();

            if (cost > dist[type][node])
                continue;

            for (auto [nxt, wt] : adj[type][node])
            {
                if (dist[type][nxt] > cost + wt)
                {
                    dist[type][nxt] = cost + wt;
                    ways[type][nxt] = ways[type][node];

                    dist2[type][nxt] = cost + wt;
                    ways2[type][nxt] = ways2[type][node];

                    pq.push({cost + wt, nxt});
                }
                else if (dist[type][nxt] == cost + wt)
                {
                    dist[type][nxt] = cost + wt;
                    ways[type][nxt] += ways[type][node];

                    ways[type][nxt] %= modular;

                    dist2[type][nxt] = cost + wt;
                    ways2[type][nxt] += ways2[type][node];
                    ways2[type][nxt] %= modular2;
                }
            }
        }
    };
    go(0, 0);
    go(num - 1, 1);

    ll totalways = ways[0][num - 1] %modular, mini = dist[0][num - 1];
    ll totalways2 = ways2[0][num - 1] %modular2, mini2 = dist2[0][num - 1];
    vector<ll> ans;
    for (ll i = 0; i < num; i++)
    {
        ll w1 = (ways[0][i] * ways[1][i])%modular;
        
        ll w2 = (ways2[0][i] * ways2[1][i])%modular2;
        
        if (((totalways == w1) && (mini == dist[0][i] + dist[1][i])) &&
            ((totalways2 == w2) && (mini2 == dist2[0][i] + dist2[1][i])))
        {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it + 1 << " ";
    cout << endl;
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