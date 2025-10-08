/*
Problem: Sum of Three Values
Link: https://cses.fi/problemset/task/1641/
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





void solve()
{
   ll num,sum;
   cin>>num>>sum;
   vector<pair<ll,ll>>vec;
   for(ll i=1;i<=num;i++){
    ll x;
    cin>>x;
    vec.push_back({x,i});
   }sort(vec.begin(),vec.end());

   for(ll i=0;i<num-2;i++){
    ll start=i+1, end=num-1;
    while(start<end){
        ll total=vec[i].first+vec[start].first+vec[end].first;
        if(total==sum){cout<<vec[i].second<<" "<<vec[start].second<<" "<<vec[end].second;
        return;}
        if(total>sum && end-start==1)break;
        else if(total>sum)end--;
        else if(total<sum)start++;

    }
   }cout<<"IMPOSSIBLE\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    n = 1;
    //cin >> n;
    for (ll i = 1; i <= n; ++i)
    {
        // cout << "Case " << i << ": ";
        solve();
    }
    
    return 0;
}