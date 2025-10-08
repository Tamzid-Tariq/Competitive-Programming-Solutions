/*
Problem: Minimizing Coins
Link: https://cses.fi/problemset/task/1634/
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
const ll INF =10000000;

ll num, sum;
vector<ll> ans(1000006);

void precalc(vector<ll> &vect)
{
    ans[0] = 0;
    for (ll i = 1; i <= sum; i++)
    {

        for (ll j = 0; j < num; j++)
        {
            if (vect[j] > i)
            {
                break;
            }
            ans[i] = min(ans[i], 1 + ans[i - vect[j]]);
            // cout<<i<<" "<<ans[i]<<" ";
        }
    }
}

void solve()
{

    cin >> num >> sum;
    vector<ll> vec(num);
    ans.assign(sum + 1, INF);
    for (auto &it : vec)
        cin >> it, ans[it] = 1;
    sort(vec.begin(),vec.end());
    precalc(vec);
    (ans[sum]==INF)?(cout<<-1<<endl):(cout << ans[sum] << endl);
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