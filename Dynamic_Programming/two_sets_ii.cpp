/*
Problem: Two Sets II
Link: https://cses.fi/problemset/task/1093/
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

ll num, needed;
ll ans[65000][506];

ll go_recurse(ll val, ll required)
{
    if (required == 0)
        return 1;
    if (val > num || required < val)
        return 0;
    if (ans[required][val] != -1)
        return ans[required][val];

    ll times = go_recurse(val + 1, required);
    times %= modular;
    ll times2 = (required >= val) ? (go_recurse(val + 1, required - val)) : 0;
    times2 %= modular;

    times = (times + times2) % modular;

    return ans[required][val] = times;
}

ll modularBinaryExponentiation(ll base, ll exponent)
{
    if (exponent == 0)
        return 1;
    ll result = modularBinaryExponentiation(base, exponent / 2);
    if (exponent & 1)
        return (((((result * result)) % modular) * base) % modular);
    else
        return ((result * result) % modular);
}

void solve()
{
    cin >> num;
    ll total_sum = (num) * (num + 1) / 2;
    if (total_sum & 1)
    {
        cout << 0 << endl;
        return;
    }
    needed = total_sum / 2;
    
    memset(ans, -1, sizeof(ans));

    ll result = go_recurse(1, needed);
    ll multiply = modularBinaryExponentiation(2, modular - 2);
    result *= multiply;
    cout << result % modular << endl;
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