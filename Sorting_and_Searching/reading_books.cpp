/*
Problem: Reading Books
Link: https://cses.fi/problemset/task/1631/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int;

using namespace std;

void solve()
{
    ll num;
    cin >> num;
    vector<ll>vec(num);
    ll sum=0,maxi=0;
    for(auto &it:vec){
        cin>>it;
        sum+=it;
        maxi=max(maxi,it);
    }if(maxi>sum-maxi)cout<<2*maxi;
    else cout<<sum<<endl;

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
        solve();
    }
    return 0;
}