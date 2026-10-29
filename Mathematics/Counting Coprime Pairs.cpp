/*
Problem: Counting Coprime Pairs
Link: https://cses.fi/problemset/task/2417/
Author: Tamzid Tariq
Date: 2026-02-15
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

    vector<ll> vec(num);
    for (auto &it : vec)
        cin >> it;

    ll maxi = *max_element(vec.begin(), vec.end());
    vector<ll> all(maxi + 2);

    for (auto it : vec)
        all[it]++;

    for (ll i = 1; i <= maxi; i++)
    {
        for (ll j = 2 * i; j <= maxi; j += i)
        {
            all[i] += all[j];
        }
        all[i] = (all[i] * (all[i] - 1)) / 2;
    }

    for (ll i = maxi; i >= 1; i--)
    {
        for (ll j = 2 * i; j <= maxi; j += i)
        {
            all[i] -= all[j];
        }
    }
    cout << all[1] << endl;
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