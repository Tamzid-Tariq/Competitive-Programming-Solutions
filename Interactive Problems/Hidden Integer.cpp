/*
Problem: Hidden Integer
Link: https://cses.fi/problemset/task/3112/
Author: Tamzid Tariq
Date: 2026-02-15
Status: Accepted ✓
*/

#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// #define endl '\n';
const ll modular = 1e9 + 7;
const double pi = acos(-1.0);
const ll INF = 1e18;



void solve()
{
    ll lo=1,hi=1000000000,ans=0;

    function<bool(ll)>ask=[&](ll val)
    {
        cout<<"? "<<val<<endl;

        string s;
        cin>>s;

        return (s=="YES");
    };

    while(lo<=hi)
    {
        ll mid=(lo+hi)>>1LL;

        if(ask(mid))
        {
            lo=mid+1;
        }
        else 
        {
            ans=mid;
            hi=mid-1;
        }
    }
    cout<<"! "<<ans<<endl;
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