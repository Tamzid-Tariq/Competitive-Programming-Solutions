/*
Problem: Missing Coin Sum
Link: https://cses.fi/problemset/task/2183/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>
    
    using namespace std;
    using ll = long long int;


    void solve(){
        ll n,count=0;
    
        cin>>n;
        vector<ll>vec;
        
        for(ll i=0;i<n;i++){
            ll k;
            cin>>k;
            vec.push_back(k);
        }
        sort(vec.begin(),vec.end());
        ll max=1;
        ll ans=0;
        
        for(ll i=0;i<n;i++){
            if(vec[i]<=max){(max+=vec[i]);}
            else{break;}
            
            }
            cout<<max<<endl;
    } 

    int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
      
    //ll n;
    //cin>>n;
    //while(n--){
        solve();
    //}
    return 0;
    }