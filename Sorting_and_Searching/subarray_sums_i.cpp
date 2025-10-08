/*
Problem: Subarray Sums I
Link: https://cses.fi/problemset/task/1660/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int;

using namespace std;

void solve()
{
    ll num, target;
    cin >> num >> target;
    vector<ll> vec(num);
    map<ll, ll> mp;
    ll sum[num + 1];
    sum[0] = 0;
    mp[0]++;
    for (ll i = 0; i < num; i++)
    {
        cin >> vec[i];
        sum[i + 1] = sum[i] + vec[i];
    }

    ll ans = 0;
    for (ll start = 1; start <= num; start++)
    {
        ll need = sum[start] - target;
        ans += mp[need];
        mp[sum[start]]++;
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
        solve();
    }
    return 0;
}