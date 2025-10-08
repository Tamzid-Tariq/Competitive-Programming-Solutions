/*
Problem: Raab Game I
Link: https://cses.fi/problemset/task/3399/
Author: Tamzid Tariq
Date: 2025-10-08
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
    ll num, a, b;
    cin >> num >> a >> b;

    ll draw=num-a-b;

    if(max(a,b)==num || a+b && min(a,b)==0 || (a+b)>num)
    {
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";
    vector<ll>alice,bob;

    for(ll i=0;i<draw;i++)
    {
        alice.push_back({num-i});
        bob.push_back({num-i});
    }

    for(ll j=0;j<num-draw;j++)
    {
        alice.push_back({j+1});
        bob.push_back((a+j)%(num-draw) +1);
    }
    for(auto it:alice)cout<<it<<" ";
    cout<<endl;

    for(auto it:bob)cout<<it<<" ";
    cout<<endl;
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