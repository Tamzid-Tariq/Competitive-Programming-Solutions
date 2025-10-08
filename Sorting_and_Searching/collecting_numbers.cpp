/*
Problem: Collecting Numbers
Link: https://cses.fi/problemset/task/2216/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int ;
using ull=unsigned long long int;
using namespace std;
const ll maximum=1e9+7;


void solve(){
    ll n,m;
    cin>>n>>m;
    ll arr[n+2]={0};
    ll index[n+2]={0};

    for(ll i=1;i<=n;i++){
    cin>>arr[i];
    index[arr[i]]=i;
    }ll count=1;
    for(ll j=1;j<n;j++){
    if(index[j]>index[j+1]){count++;}
    }cout<<count;

    }


 int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
   /* ll n;
    cin>>n;

    for(ll i=1;i<=n;i++){*/
    solve();
      //      }
    }