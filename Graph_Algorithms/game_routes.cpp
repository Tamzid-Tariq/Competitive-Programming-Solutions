/*
Problem: Game Routes
Link: https://cses.fi/problemset/task/1681/
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

ll levels, teleporter;
vector<vector<ll>> adjacent(100005);

bool isvisited[100005];
bool visitdone[100005];

ll ans[100005];

ll result(ll vertex)
{
    isvisited[vertex] = 1;

    if (visitdone[vertex])
        return ans[vertex];

    ll val = 0;

    for (auto it : adjacent[vertex])
    {
        val += result(it);
        val %= modular;
    }
    visitdone[vertex] = 1;

    return ans[vertex] = (val % modular);
}

void solve()
{

    cin >> levels >> teleporter;
    ans[levels] = 1;
    visitdone[levels] = 1;

    for (ll i = 0; i < teleporter; i++)
    {
        ll x, y;
        cin >> x >> y;
        adjacent[x].push_back(y);
    }

    cout << (result(1) % modular) << endl;
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