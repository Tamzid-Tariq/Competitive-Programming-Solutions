/*
Problem: Maximum Manhattan Distances
Link: https://cses.fi/problemset/task/3410/
Author: Tamzid Tariq
Date: 2026-03-16
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

    vector<pair<ll, ll>> vec(num);

    ll mina = INF, maxa = -INF, minb = INF, maxb = -INF;

    // a -> (x1 + y1) - (x2 + y2)

    // b -> (x1 - y1) - (x2 - y2)
    for (auto &[it, lit] : vec)
    {
        cin >> it >> lit;

        ll a = it + lit, b = it - lit;
        mina = min(mina, a), maxa = max(maxa, a), minb = min(b, minb), maxb = max(maxb, b);

        cout << max(maxa - mina, maxb - minb) << endl;
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