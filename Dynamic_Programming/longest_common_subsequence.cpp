/*
Problem: Longest Common Subsequence
Link: https://cses.fi/problemset/task/3403/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
#define endl '\n';
const ll modular = 1e6 + 7;
const double pi = acos(-1.0);
const ll INF = 1e18;

void solve()
{
    ll num1, num2;
    cin >> num1 >> num2;

    vector<ll> one(num1), two(num2);

    for (auto &it : one)
        cin >> it;

    for (auto &it : two)
        cin >> it;

    vector<vector<ll>> ans(num1 + 2, vector<ll>(num2 + 2, -1));

    function<ll(ll, ll)> go = [&](ll pos1, ll pos2)
    {
        if (pos1 == num1 || pos2 == num2)
            return ans[pos1][pos2]=0LL;

        if (ans[pos1][pos2] != -1)
            return ans[pos1][pos2];

        ll ret = 0;
        if (one[pos1] == two[pos2])
        {
            ret = max(ret, 1 + go(pos1 + 1, pos2 + 1));
        }
        ret = max({ret, go(pos1, pos2 + 1), go(pos1 + 1, pos2)});

        return ans[pos1][pos2] = ret;
    };

    ll got = go(0, 0);

    cout << got << endl;

    // for (ll i = 0; i < num1; i++)
    // {
    //     for (ll j = 0; j < num2; j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    function<void(ll, ll, ll)> go_recurse = [&](ll pos1, ll pos2, ll need)
    {
        if (!need)
            return;

        if (pos1 == num1 || pos2 == num2)
            return;
        // cout << pos1 << " " << pos2 << endl;

        ll got1 = ans[pos1+1][pos2],got2=ans[pos1][pos2+1];

        if (ans[pos1][pos2] > max(got1,got2) )
        {
            cout<<one[pos1]<<" ";
            go_recurse(pos1 + 1, pos2 + 1, need - 1);
        }
            
        else if(got1>got2)
        {
            // if(ans[pos1][pos2]>ans[pos1+1][pos2])cout<<two[pos2]<<" ";
            go_recurse(pos1 + 1, pos2, need);
        }
        else go_recurse(pos1, pos2 + 1, need);
            
    };

    go_recurse(0, 0, got);
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