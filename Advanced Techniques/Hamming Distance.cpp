/*
Problem: Hamming Distance
Link: https://cses.fi/problemset/task/2136/
Author: Tamzid Tariq
Date: 2026-02-16
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
    ll num, len;
    cin >> num >> len;

    vector<ll> vec(num);
    for (ll i = 0; i < num; i++)
    {
        string s;
        cin >> s;

        ll got = 0;
        for (ll j = 0; j < len; j++)
            if (s[j] == '1')
                got |= (1LL << j);
        vec[i] = got;
    }

    ll ans = len;
    for (ll i = 0; i < num - 1; i++)
    {
        for (ll j = i + 1; j < num; j++)
        {
            ans = min(ans, (ll)__builtin_popcount(vec[i] ^ vec[j]));
        }
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