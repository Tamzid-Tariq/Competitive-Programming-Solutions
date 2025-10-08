/*
Problem: Binomial Coefficients
Link: https://cses.fi/problemset/task/1079/
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
const ll INF = 10000000000LL;

ll factorial[1000006];

void precompute()
{
    factorial[0] = factorial[1] = 1;

    for (ll i = 2; i <= 1000000; i++)
        factorial[i] = (factorial[i - 1] * i) % modular;
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

ll ncr(ll n, ll r)
{
    if(r>n)return 0;

    ll ret=factorial[n];
    ret=(ret*modularBinaryExponentiation(factorial[r],modular-2))%modular;
    ret=(ret*modularBinaryExponentiation(factorial[n-r],modular-2))%modular;
    
    return ret;
}

void solve()
{
    ll n, r;
    cin >> n >> r;

    cout << ncr(n, r) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    precompute();

    ll n;
    n = 1;
    cin >> n;
    for (ll i = 1; i <= n; ++i)
    {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}