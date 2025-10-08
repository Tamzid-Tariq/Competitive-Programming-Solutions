/*
Problem: Two Knights
Link: https://cses.fi/problemset/task/1072/
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

void solve()
{
    ll times;
    cin >> times;

    for (ll num = 1; num <= times; num++)
    {
        ll ans = (num - 1) * (num + 4) * (num * num - 3 * num + 4) / 2;

        cout << ans << endl;
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