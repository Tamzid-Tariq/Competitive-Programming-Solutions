/*
Problem: Subarray Divisibility
Link: https://cses.fi/problemset/task/1662/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int;
using ull = unsigned long long int;
using namespace std;
const ll modular = 1e9 + 7;
const double pi = 22 / 7;

void solve()
{
    ll num;
    cin >> num;
    vector<ll> vec;
    int remain[num + 1];
    remain[0] = 0;
    for (ll i = 1; i <= num; i++)
    {
        ll x;
        cin >> x;
        vec.push_back(x);
        remain[i] = (remain[i - 1] + x) % num;
        if(remain[i]<0)remain[i]+=num;
    }
    map<ll, ll> mp;
    mp[0]++;
    ll ans = 0;
    for (ll i = 1; i <= num; i++)
    {
        ll need = remain[i];
        ans += mp[need];
        mp[remain[i]]++;
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