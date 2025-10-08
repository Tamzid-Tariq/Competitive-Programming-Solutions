/*
Problem: Prime Multiples
Link: https://cses.fi/problemset/task/2185/
Author: Tamzid Tariq
Date: 2025-10-08
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
    ll val, num;
    cin >> val >> num;

    vector<ll> vec(num);
    for (auto &it : vec)
        cin >> it;

    ll ans = 0;

    function<void(ll, int, bool)> go_recurse = [&](ll LCM, int pos, bool even)
    {
        if (pos >= num)
            return;

        go_recurse(LCM, pos + 1, even);

        if((val/LCM) < vec[pos])return;

        LCM *=vec[pos];
        
        ans += (ll)(val / LCM) * ((even) ? -1 : 1);
        go_recurse(LCM, pos + 1, 1-even);
    };

    go_recurse(1, 0, 0);

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