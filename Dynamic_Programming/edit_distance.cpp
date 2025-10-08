/*
Problem: Edit Distance
Link: https://cses.fi/problemset/task/1639/
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

int dp[5002][5002];

void solve()
{
    string one, two;
    cin >> one >> two;

    ll siz1 = one.size(), siz2 = two.size();
    ll maxi=max(siz1,siz2);
    for (ll i = 0; i <= siz1; i++)
    {
        for (ll j = 0; j <= siz2; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = max(i, j);
            }
            else
            {
                if (one[i - 1] != two[j - 1])
                {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
                else
                    dp[i][j] = dp[i-1][j-1];
            }
        }
    }
    cout << dp[siz1][siz2] << endl;
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