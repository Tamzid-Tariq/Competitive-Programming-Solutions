/*
Problem: Stick Lengths
Link: https://cses.fi/problemset/task/1074/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>
     
    using namespace std;
    using ll = long long int;
        
    int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
     
    ll n;
    cin>>n;
    vector<ll>vec;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        vec.push_back(x);
    }sort(vec.begin(),vec.end());
    ll ans=vec[n/2];
    ll sum=0;
    for(auto it:vec){
        sum+=abs(it-ans);
    }
    cout<<sum<<endl;
    
    return 0;
    }