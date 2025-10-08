/*
Problem: Trailing Zeros
Link: https://cses.fi/problemset/task/1618/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int;

using ull = unsigned long long int;

using namespace std;

const ll maxi = 1e9 + 7;

ll legendre(ll n, ll p)
{

    ll xi = 0;

    while (n)
    {

        n /= p;

        xi += n;
    }

    return xi;
}

int main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);
    cout.tie(0);

    ll a;

    cin >> a;

    ll am = 2, bs = 5;

    ll y = legendre(a, bs);

    cout << y << endl;

    return 0;
}