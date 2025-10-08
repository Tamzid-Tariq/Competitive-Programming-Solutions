/*
Problem: Elevator Rides
Link: https://cses.fi/problemset/task/1653/
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

ll num, maxi;
pair<ll, ll> ans[1 << 20 + 5];
ll weight[22];

pair<ll, ll> go_recurse(ll mask)
{
    if (mask == 0)
        return {1, 0};

    if (ans[mask].first != -1)
        return ans[mask];

    pair<ll, ll> val = {num + 1, 0};

    for (ll i = 0; i < num; i++)
    {
        if (mask & (1 << i))
        {
            pair<ll, ll> other = go_recurse(mask ^ (1 << i));
            if (weight[i] + other.second > maxi)
            {
                val = min(val, {other.first + 1, weight[i]});
            }
            else
            {
                val = min(val, {other.first, other.second + weight[i]});
            }
        }
    }
    return ans[mask] = val;
}

void solve()
{
    cin >> num >> maxi;
    for (ll i = 0; i < num; i++)
    {
        cin >> weight[i];
    }

    for (ll i = 0; i < (1 << num); i++)
    {
        ans[i] = {-1, -1};
    }
    cout << go_recurse((1 << num) - 1).first << endl;
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