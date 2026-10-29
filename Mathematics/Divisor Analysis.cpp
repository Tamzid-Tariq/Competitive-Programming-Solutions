/*
Problem: Divisor Analysis
Link: https://cses.fi/problemset/task/2182/
Author: Tamzid Tariq
Date: 2026-02-14
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

ll modularBinaryExponentiation(ll base, ll exponent)
{
    if (exponent == 0)
        return 1;

    ll result = modularBinaryExponentiation(base, exponent / 2);
    result %= modular;

    if (exponent & 1)
        return (((((result * result)) % modular) * base) % modular);
    else
        return ((result * result) % modular);
}

ll add(ll val1, ll val2)
{
    ll result = (val1 % modular) + (val2 % modular);
    return result % modular;
}

ll subtract(ll val1, ll val2)
{
    ll result = modular + ((val1 % modular) - (val2 % modular));
    return result % modular;
}

ll multiply(ll val1, ll val2)
{
    ll result = (val1 % modular) * (val2 % modular);
    return result % modular;
}

ll divide(ll val1, ll val2)
{
    ll denominator = modularBinaryExponentiation(val2 % modular, modular - 2) % modular;
    ll result = multiply(val1, denominator);

    return result % modular;
}

ll exponentiation(ll base, ll power, ll mod)
{
    if (power == 0)
        return 1;
    ll result = exponentiation(base, power / 2, mod);
    result = ((result % mod) * (result % mod)) % mod;
    if (power & 1)
        result = ((result * base) % mod);
    return result;
}

void solve()
{
    ll num;
    cin >> num;

    vector<pair<ll, ll>> vec(num);
    for (auto &[it, lit] : vec)
        cin >> it >> lit;

    ll times = 1, sum = 1, product = 1, val = 1, power = 1;

    bool got = 1;
    for (auto [it, lit] : vec)
    {
        if (lit & 1)
            got = 0;

        val = multiply(val, modularBinaryExponentiation(it, lit));

        times = multiply(times, (lit + 1));

        power *= (lit + 1) % (2 * modular - 2);
        power %= (2 * modular - 2);

        ll now = subtract(modularBinaryExponentiation(it, lit + 1), 1);
        now = divide(now, it - 1);

        sum = multiply(sum, now);
    }

    for (auto [it, lit] : vec)
    {
        ll now = (lit * power) / 2;
        now %= (modular - 1);
        product = multiply(product, modularBinaryExponentiation(it, now));
    }

    cout << times << " " << sum << " " << product << endl;
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