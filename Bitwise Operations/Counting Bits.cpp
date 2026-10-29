/*
Problem: Counting Bits
Link: https://cses.fi/problemset/task/1146/
Author: Tamzid Tariq
Date: 2026-03-09
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
    ll num;
    cin >> num;

    ll now = 1, ans = 0;

    while (now <= num)
    {
        ll siz = now, gap = 2 * siz, remainder = num % gap;

        ans += (num / gap) * siz + max(0LL, remainder - siz + 1LL);
        now <<= 1LL;
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