/*
Problem: Shortest Routes II
Link: https://cses.fi/problemset/task/1672/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int;
using ull = unsigned long long int;
using namespace std;
const ll modular = 1e9 + 7;
const double pi = 22 / 7;
const ll INF = LLONG_MAX;

void solve()
{
    ll city, road, query;
    cin >> city >> road >> query;

    ull dis[city + 1][city + 1];
    for (ll i = 0; i <= city; i++)
    {
        for (ll j = 0; j <= city; j++)
        {
            dis[i][j] = INF;
        }
    }

    // memset(dis, 100000000000000000LL, sizeof(dis));

    for (ll i = 0; i < road; i++)
    {
        ll path1, path2, len;
        cin >> path1 >> path2 >> len;

        dis[path1][path2] = min(dis[path1][path2],(ull)len);
        dis[path2][path1] = min(dis[path2][path1],(ull)len);
    }

    for (ll k = 1; k <= city; k++)
    {
        for (ll i = 1; i <= city; i++)
        {
            dis[i][i] = 0;
            for (ll j = 1; j <= city; j++)
            {
                // cout<<i<<" "<<j<<" "<<dis[i][j]<<" ";
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                // cout<<i<<" "<<j<<" "<<dis[i][j]<<endl;
            }
        }
    }
    while (query--)
    {
        ll path1, path2;
        cin >> path1 >> path2;
        if (dis[path1][path2] == INF)
            cout << -1 << endl;
        else
            cout << dis[path1][path2] << endl;
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