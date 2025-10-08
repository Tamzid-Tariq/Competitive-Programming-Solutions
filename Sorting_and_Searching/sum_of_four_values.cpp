/*
Problem: Sum of Four Values
Link: https://cses.fi/problemset/task/1642/
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
    ll siz, sum;
    cin >> siz >> sum;
    vector<pair<ll, ll>> vec;
    for (ll i = 1; i <= siz; i++)
    {
        ll x;
        cin >> x;
        vec.push_back({x, i});
    }
    sort(vec.begin(), vec.end());
    // for(auto it:vec)cout<<it.first<<" ";
    for (ll start1 = 0; start1 < siz - 3; start1++)
    {
        for (ll start2 = start1 + 1; start2 < siz - 2; start2++)
        {
            ll end1 = start2 + 1;
            ll end2 = siz - 1;
            while (end1 < end2)
            {
                ll total = vec[start1].first + vec[start2].first + vec[end1].first + vec[end2].first;

                if (total == sum)
                {
                    cout << vec[start1].second << " " << vec[start2].second << " " << vec[end1].second << " " << vec[end2].second;
                    return;
                }
                else if (total > sum)
                    end2--;
                else if (total < sum)
                    end1++;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
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