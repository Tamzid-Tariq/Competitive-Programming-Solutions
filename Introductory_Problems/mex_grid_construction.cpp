/*
Problem: Mex Grid Construction
Link: https://cses.fi/problemset/task/3419/
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
    ll num;
    cin >> num;

    for (ll i = 0; i < num; i++)
    {
        for (ll j = 0; j < num; j++)
            cout << (i ^ j) << " ";
        cout << endl;
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