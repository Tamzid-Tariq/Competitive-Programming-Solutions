/*
Problem: Meet in the Middle
Link: https://cses.fi/problemset/task/1628/
Author: Tamzid Tariq
Date: 2026-02-16
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
    ll num, need;
    cin >> num >> need;

    unordered_map<ll,ll>mp;

    vector<ll> vec(num);
    for (auto &it : vec)
        cin >> it;

    sort(vec.begin(),vec.end());

    while(vec.size() && vec.back()>need)vec.pop_back();

    num=vec.size();
    ll siz = num / 2, ans = 0;

    for (ll i = 0; i < (1LL << siz); i++)
    {
        ll total = 0;
        for (ll j = 0; j < siz; j++)
        {
            if (i & (1LL << j))
                total += vec[j];
        }
        if (total <= need)
            mp[total]++;
    }

    siz = num - siz;

    for (ll i = 0; i < (1LL << siz); i++)
    {
        ll total = 0;
        for (ll j = 0; j < siz; j++)
        {
            if (i & (1LL << j))
                total += vec[num / 2 + j];
        }
        if (total <= need && mp.count(need-total))
        {
            ans += mp[need - total];
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