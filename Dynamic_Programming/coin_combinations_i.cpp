/*
Problem: Coin Combinations I
Link: https://cses.fi/problemset/task/1635/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int;
using ull = unsigned long long int;
using namespace std;
const ll MOD = 1e9 + 7;
const double pi = 22 / 7;
const ll INF = LLONG_MAX;

ll num, sum;
ll ans[1000006];

void precalc(vector<ll> value)
{
    ans[0] = 1;

    for (ll i = 1; i <= sum; i++)
    {
        for (ll j = 0; j < num; j++)
        {
            if (value[j] >= i)
                break;
            ans[i] += (ans[i - value[j]]);
            ans[i] %= MOD;
        }
    }
}

void solve()
{

    cin >> num >> sum;
    vector<ll> vec(num);
    for (auto &it : vec)
        cin >> it, ans[it]++;

    sort(vec.begin(), vec.end());
    precalc(vec);

    cout << ans[sum] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    n = 1;
    // cin >> n;
    for (ll kick = 1; kick <= n; ++kick)
    {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}