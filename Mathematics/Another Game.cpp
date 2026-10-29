/*
Problem: Another Game
Link: https://cses.fi/problemset/task/2208/
Author: Tamzid Tariq
Date: 2026-02-14
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
    cin>>num;
    
    bool pos=0;

    vector<ll>vec(num);
    for(auto &it:vec)
    {
        cin>>it;
        pos|=(it%2);
    }

    cout<<(pos?"first\n":"second\n");
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    n = 1;
    cin >> n;
    for (ll i = 1; i <= n; ++i)
    {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}