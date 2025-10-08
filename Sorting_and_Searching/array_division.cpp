/*
Problem: Array Division
Link: https://cses.fi/problemset/task/1085/
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
    ll num, division;
    cin >> num >> division;
    ll maxi = LLONG_MIN, sum = 0;
    vector<ll> vec(num);
    for (auto &it : vec)
    {
        cin >> it;
        maxi = max(it, maxi);
        sum += it;
    }
    ll low = maxi, high = sum;
    ll ans = high;
    while (low <= high)
    {
        ll partition = 1;
        ll mid = (low + high) / 2;
        ll total = 0;
        for (ll i = 0; i < num; i++)
        {
            if (vec[i] + total > mid)
            {
                partition++;
                total = 0;
            }
            total += vec[i];
        }
        if (partition > division)
        {
            low = mid + 1;
        }
        else
        {
            ans = min(ans, mid);
            high = mid - 1;
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