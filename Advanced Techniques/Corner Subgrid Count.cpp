/*
Problem: Corner Subgrid Count
Link: https://cses.fi/problemset/task/2137/
Author: Tamzid Tariq
Date: 2026-02-17
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

#pragma GCC target("popcnt")

void solve()
{
    ll num;
    cin >> num;

    bitset<3000> bits[num];

    for (ll i = 0; i < num; i++)
    {
        cin >> bits[i];
    }

    ll ans = 0;

    for (ll i = 0; i + 1 < num; i++)
    {
        for (ll j = i + 1; j < num; j++)
        {
            bitset<3000> now = (bits[i] & bits[j]);

            ll times = now.count();
            ans += times * (times - 1) / 2;
        }
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