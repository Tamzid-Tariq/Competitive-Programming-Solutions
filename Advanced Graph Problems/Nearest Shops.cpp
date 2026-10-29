/*
Problem: Nearest Shops
Link: https://cses.fi/problemset/task/3303/
Author: Tamzid Tariq
Date: 2026-08-22
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
    ll num, edges, cnt;
    cin >> num >> edges >> cnt;

    vector<ll> good(num), vec(cnt);
    for (auto &it : vec)
    {
        cin >> it;
        good[--it]++;
    }
    vector<vector<ll>> adj(num);
    for (ll i = 0; i < edges; i++)
    {
        ll from, to;
        cin >> from >> to;

        adj[--from].push_back(--to);
        adj[to].push_back(from);
    }

    queue<tuple<ll, ll, ll>> q;
    vector<ll> times(num);
    vector<vector<ll>> dist(num, vector<ll>(3, INF));
    vector<vector<ll>> who(num, vector<ll>(3, INF));

    for (auto it : vec)
    {
        dist[it][times[it]] = 0;
        who[it][times[it]] = it;
        times[it]++;
        q.push({it, 0, it});
    }

    while (!q.empty())
    {
        auto [node, cost, par] = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (times[it] < 2)
            {
                if (times[it] && who[it][times[it] - 1] == par)
                    continue;

                dist[it][times[it]] = cost + 1;
                who[it][times[it]] = par;
                times[it]++;
                q.push({it, cost + 1, par});
            }
        }
    }

    for (ll i = 0; i < num; i++)
        cout << (dist[i][good[i]] == INF ? -1 : dist[i][good[i]]) << " ";
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