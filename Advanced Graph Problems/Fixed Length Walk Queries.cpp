/*
Problem: Fixed Length Walk Queries
Link: https://cses.fi/problemset/task/3357/
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
const ll N = 2505;

ll dist[N][N][2];

void solve()
{
    ll num, edges, queries;
    cin >> num >> edges >> queries;

    vector<vector<ll>> adj(num);
    for (ll i = 1; i <= edges; i++)
    {
        ll from, to;
        cin >> from >> to;

        adj[--from].push_back(--to);
        adj[to].push_back(from);
    }

    for (ll i = 0; i < num; i++)
    {
        for (ll j = 0; j < num; j++)
        {
            dist[i][j][0] = dist[i][j][1] = INF;
        }
    }

    queue<pair<ll, ll>> q;
    for (ll i = 0; i < num; i++)
    {
        q.push({i,0});
        dist[i][i][0] = 0;

        while (!q.empty())
        {
            auto [node, cost] = q.front();
            q.pop();

            if (dist[i][node][cost % 2] < cost)
                continue;

            for (auto it : adj[node])
            {
                if (dist[i][it][(cost + 1) % 2] > cost + 1)
                {
                    dist[i][it][(cost + 1) % 2] = cost + 1;
                    q.push({it, cost + 1});
                }
            }
        }
    }

    for (ll i = 0; i < queries; i++)
    {
        ll start, end, x;
        cin >> start >> end >> x;
        start--, end--;

        if (dist[start][end][x % 2]<=x)
        {
            cout<<"YES\n";
        }
        else cout<<"NO\n";
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