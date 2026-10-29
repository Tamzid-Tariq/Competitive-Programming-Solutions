/*
Problem: Counting Tilings
Link: https://cses.fi/problemset/task/2181/
Author: Tamzid Tariq
Date: 2025-12-09
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

ll ans[(1LL << 10) + 2][12][1003];

ll add(ll val1, ll val2)
{
    ll result = (val1 % modular) + (val2 % modular);
    return result % modular;
}

ll multiply(ll val1, ll val2)
{
    ll result = (val1 % modular) * (val2 % modular);
    return result % modular;
}

void solve()
{
    ll row, col;
    cin >> row >> col;

    memset(ans, -1, sizeof(ans));

    function<ll(ll, ll, ll)> go = [&](ll mask, ll current, ll pos)
    {
        
        if (current >= row)
            return go(mask, 0, pos + 1);

        if (pos >= col)
            return  (ll)(mask == 0LL);

        if (ans[mask][current][pos] != -1)
            return ans[mask][current][pos];

        ll ret = 0LL;

        if (mask & (1LL << current))
            ret = add(ret, go((mask ^ (1LL << current)), current + 1, pos));
        else
        {
            ret = add(ret, go((mask ^ (1LL << current)), current + 1, pos));

            if (current + 1 < row && !(mask & (1LL << (current + 1))))
                ret = add(ret, go(mask, current + 2, pos));
        
        }

        return ans[mask][current][pos] = ret;
    };

    cout << go(0, 0, 0) << endl;
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