/*
Problem: Subarray Squares
Link: https://cses.fi/problemset/task/2086/
Author: Tamzid Tariq
Date: 2026-02-18
Status: Accepted ✓
*/

#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
#define endl '\n'
const ll modular = 1e9 + 7;
const double pi = acos(-1.0);
const ll INF = 1e18;

void solve()
{
    ll num, k;
    cin >> num >> k;

    vector<ll> vec(num);
    for (auto &it : vec)
        cin >> it;

    vector<ll> pref(num + 2), weightedpref(num + 2);
    for (ll i = 1; i <= num; i++)
    {
        pref[i] = vec[i - 1] + pref[i - 1];
        weightedpref[i] = vec[i - 1] * i + weightedpref[i - 1];
    }

    function<ll(ll, ll)> costfunc = [&](ll start, ll end)
    {
        return (pref[end]-pref[start-1]) * (pref[end] - pref[start-1]);
    };

    vector<vector<ll>> ans(k + 1, vector<ll>(num + 1, INF));
    
    function<void(ll, ll, ll, ll, ll)> go = [&](ll times, ll start, ll end, ll lo, ll hi)
    {
        if (lo > hi)
            return;

        ll mid = (lo + hi+1) / 2, bestval = INF, bestpos = start;

        for (ll i = start; i <= min(mid,end); i++)
        {
            ll now = ans[times - 1][i-1] + costfunc(i, mid);

            if (now < bestval)
            {
                ans[times][mid] = now;
                bestval = now;
                bestpos = i;
            }
        }

        go(times, start, bestpos, lo, mid - 1);
        go(times, bestpos, end, mid + 1, hi);
    };

    for (ll i = 1; i <= num; i++)
    {
        ans[1][i] = costfunc(1, i);
        // cout<<ans[1][i]<<" ";
    }
    // cout<<endl;

    for (ll i = 2; i <= k; i++) 
        go(i, 1, num, 1, num);

    cout<<ans[k][num]<<endl;
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