/*
Problem: Sliding Window Or
Link: https://cses.fi/problemset/task/3405/
Author: Tamzid Tariq
Date: 2026-02-08
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

ll arr[10000002];

void solve()
{
    ll num, k;
    cin >> num >> k;

    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    arr[1] = x;
    for (int i = 2; i <= num; i++)
    {
        arr[i] = (a * arr[i - 1] + b) % c;
    }

    ll ans = 0LL;

    for(ll j=0;j<=30;j++)
    {
        ll last=0;
        for(ll i=1;i<=num;i++)
        {
            if(arr[i]&(1LL<<j))last=i;

            if(i>=k && last+k-1>=i)ans^=(1LL<<j);
        }
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