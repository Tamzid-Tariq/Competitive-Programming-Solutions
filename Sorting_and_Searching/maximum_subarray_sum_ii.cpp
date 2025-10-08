/*
Problem: Maximum Subarray Sum II
Link: https://cses.fi/problemset/task/1644/
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
    ll num, mini, maxi;
    cin >> num >> mini >> maxi;

    vector<ll> vec(num);

    for (auto &it : vec)
        cin >> it;

    ll prefsum[num + 2];
    prefsum[0] = 0;

    multiset<ll> ms;

    ll ans = LLONG_MIN;

    for (ll i = 1; i <= num; i++)
    {
        prefsum[i] = prefsum[i - 1] + vec[i - 1];
        // cout<<prefsum[i]<<" ";
        if (i >= mini)
        {
            ms.insert(prefsum[i]);

            ans = max(ans, *(ms.rbegin()) - prefsum[max(0LL, i - maxi)]);

            if (i >= maxi)
                ms.erase(ms.find(prefsum[i - maxi + mini]));
        }
    }
    for (ll i = 1; i <= maxi - mini; i++)
    {
        ans = max(ans, *(ms.rbegin()) - prefsum[num + i - maxi]);
        ms.erase(ms.find(prefsum[num + i - maxi + mini]));
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