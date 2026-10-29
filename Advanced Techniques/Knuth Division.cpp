/*
Problem: Knuth Division
Link: https://cses.fi/problemset/task/2088/
Author: Tamzid Tariq
Date: 2026-05-31
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
    ll num;
    cin >> num;

    vector<ll> vec(num);
    for (auto &it : vec)
        cin >> it;

    vector<ll> prefsum(num);
    partial_sum(vec.begin(), vec.end(), prefsum.begin());

    vector<vector<ll>> ans(num + 1, vector<ll>(num + 1)), op(num + 1, vector<ll>(num + 1));

    for (ll i = 0; i < num; i++)
    {
        ans[i][i] = 0;
        op[i][i] = i;
    }
    for (ll len = 2; len <= num; len++)
    {
        for (ll start = 0; start + len - 1 < num; start++)
        {
            ll end = start + len - 1;
            ans[start][end] = INF;
            for (ll k = op[start][end - 1]; k <= min(end - 1, op[start + 1][end]); k++)
            {
                ll now = (prefsum[end] - (start ? prefsum[start - 1] : 0LL)) + ans[start][k] + ans[k + 1][end];
                if (now < ans[start][end])
                {
                    ans[start][end] = now;
                    op[start][end] = k;
                }
            }
            // cout << start << " " << end << " " << ans[start][end] << endl;
        }
    }
    cout << ans[0][num - 1] << endl;
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