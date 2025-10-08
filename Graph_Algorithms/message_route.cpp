/*
Problem: Message Route
Link: https://cses.fi/problemset/task/1667/
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

vector<ll> adjacent[100006];
ll dist[100006];
ll parent[100006];

bool bfs(ll start, ll end)
{
    queue<ll> q;
    q.push(start);
    parent[start] = -1;
    dist[start] = 1;
    while (!q.empty())
    {
        ll top = q.front();
        q.pop();
        if (top == end)
        {
            vector<ll> ans;
            ans.push_back(top);
            ll earlier = parent[top];
            while (earlier != -1)
            {
                ans.push_back(earlier);
                earlier = parent[earlier];
            }
            cout << ans.size() << endl;
            for (ll i = ans.size() - 1; i >= 0; i--)
                cout << ans[i] << " ";
                return true;
        }
        for (int x : adjacent[top])
        {
            if (dist[x] == 0)
            {
                q.push(x);
                dist[x] = dist[top] + 1;
                parent[x] = top;
            }
        }
    }return false;
}

void solve()
{
    ll computers, connection;
    cin >> computers >> connection;
    for (ll i = 0; i < connection; i++)
    {
        ll x, y;
        cin >> x >> y;
        adjacent[x].push_back(y);
        adjacent[y].push_back(x);
    }
    bool ans=(bfs(1, computers));
    if(!ans)cout<<"IMPOSSIBLE\n";
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