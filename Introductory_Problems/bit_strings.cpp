/*
Problem: Bit Strings
Link: https://cses.fi/problemset/task/1617/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int;

using ull = unsigned long long int;

using namespace std;

ll maxi = 1e9 + 7;

ll be(ll x)
{

    if (x == 0)
        return 1;

    ll ret = be(x / 2);

    ret = (ret % maxi * ret % maxi) % maxi;

    if (x & 1)
        ret = (2 % maxi * ret % maxi) % maxi;

    return ret;
}

int main()
{

    ios_base::sync_with_stdio(0);

    cin.tie(0);
    cout.tie(0);

    ll a;

    cin >> a;

    cout << be(a) << endl;

    return 0;
}