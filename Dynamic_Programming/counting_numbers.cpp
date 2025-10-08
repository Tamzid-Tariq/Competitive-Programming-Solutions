/*
Problem: Counting Numbers
Link: https://cses.fi/problemset/task/2220/
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

ll lo, high;
string s;
ll siz;

ll ans[20][11][2][2];

ll go_recurse(ll rem, ll last, bool edge, bool zero)
{
    if (rem <= 0)
        return 1;
    if (ans[rem][last][edge][zero] != -1)
        return ans[rem][last][edge][zero];

    ll maxi = s[siz - rem] - '0';
    if (!edge)
        maxi = 9;
    ll val = 0;

    for (ll i = 0; i <= maxi; i++)
    {
        // cout<<last<<i<<" \t";
        if (i == last && !zero)
            continue;
        val += go_recurse(rem - 1, i, (edge & (i == maxi)), (zero & (i == 0)));
    }
    return ans[rem][last][edge][zero] = val;
}

void solve()
{
    cin >> lo >> high;
    s = to_string(high);
    siz = s.size();

    memset(ans, -1, sizeof ans);

    ll result = go_recurse(siz, -1, 1, 1);
    // cout<<result<<endl<<endl;
    if (lo == 0)
    {
        cout << result << endl;
        return;
    }
    lo--;
    s = to_string(lo);
    siz = s.size();
    memset(ans, -1, sizeof ans);

    result -= go_recurse(siz, -1, 1, 1);
    cout << result << endl;
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