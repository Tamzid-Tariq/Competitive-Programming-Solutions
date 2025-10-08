/*
Problem: Projects
Link: https://cses.fi/problemset/task/1140/
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

void solve()
{
    ll num;
    cin >> num;
    vector<tuple<ll, ll, ll>> vec(num);

    for (ll i = 0; i < num; i++)
    {
        ll start, end, reward;
        cin >> start >> end >> reward;

        vec[i] = {end, start, reward};
    }
    sort(vec.begin(), vec.end());
    ll dp[num + 2];
    dp[0] = 0;
    memset(dp, 0, sizeof dp);

    for (ll i = 0; i < num; i++)
    {

        ll not_taken = dp[i];

        ll taken = get<2>(vec[i]);
        ll start = get<1>(vec[i]);
        ll end = get<0>(vec[1]);

        ll ind = lower_bound(vec.begin(), vec.end(), make_tuple(start, 0, 0)) - vec.begin();
        taken += dp[max(0LL, ind)];

        dp[i + 1] = max(taken, not_taken);
    }
    cout << dp[num] << endl;
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