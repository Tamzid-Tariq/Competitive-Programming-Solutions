/*
Problem: Movie Festival II
Link: https://cses.fi/problemset/task/1632/
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
    ll num, member;
    cin >> num >> member;
    multiset<pair<ll, ll>> ms;
    for (ll i = 0; i < num; i++)
    {
        ll start, finish;
        cin >> start >> finish;
        ms.insert({finish, start});
    }
    ll ans = 0;
    multiset<ll> endtimes;
    for (ll i = 0; i < member; i++)
    {
        endtimes.insert(0);
    }

    for (auto it : ms)
    {
        auto available = endtimes.upper_bound({it.second});
        //
        if (available == endtimes.begin())
            continue;
        available--;
        endtimes.erase(available);
        endtimes.insert(it.first);
        ans++;
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