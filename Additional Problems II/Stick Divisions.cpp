/*
Problem: Stick Divisions
Link: https://cses.fi/problemset/task/1161/
Author: Tamzid Tariq
Date: 2026-09-13
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
    ll len, num;
    cin >> len >> num;

    multiset<ll> need;

    vector<ll> vec(num);
    for (auto &it : vec)
    {
        cin >> it;
        need.insert(it);
    }

    if(num==1)
    {
        cout<<0<<endl;
        return;
    }

    ll ans = 0;
    while (need.size()>=2)
    {
        auto mini1 = *need.begin();
        need.erase(need.find(mini1));

        auto mini2 = *need.begin();
        need.erase(need.find(mini2));

        need.insert(mini1+mini2);
        ans += mini1+mini2;
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