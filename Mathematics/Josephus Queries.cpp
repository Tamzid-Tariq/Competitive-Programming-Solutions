/*
Problem: Josephus Queries
Link: https://cses.fi/problemset/task/2164/
Author: Tamzid Tariq
Date: 2026-02-11
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
    ll num, times;
    cin >> num >> times;

    function<ll(ll, ll)> go = [&](ll here, ll need)
    {
        if (here == 1)
            return 1LL;

        if (need * 2 <= here)
            return need * 2LL;

        if (here & 1)
        {
            if (need * 2 == here + 1)
                return 1LL;

            else
            {
                return 2 * (go(here / 2, need - (here + 1) / 2)) + 1LL;
            }
        }
        else
        {
            return 2 * (go(here / 2, need - here / 2)) - 1;
        }
    };

    cout << go(num, times) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    n = 1;
    cin >> n;
    for (ll i = 1; i <= n; ++i)
    {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}