/*
Problem: Distinct Numbers
Link: https://cses.fi/problemset/task/1621/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int ;
using ull=unsigned long long int;
using namespace std;
const ll maxi=1e9+7;



void solve(){
 ll N;
 cin>>N;
 set<ll>ans;
    while(N--){
        ll x;
        cin>>x;
        ans.insert(x);
               }cout<<ans.size()<<endl;
}

 int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();

    }