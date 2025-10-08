/*
Problem: Collecting Numbers II
Link: https://cses.fi/problemset/task/2217/
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
    }//cout<<count;//solution of collecting numbers I

    while(m--){
        ll left,right;
        cin>>left>>right;
        set<pair<ll,ll>>s;
        if(arr[left]!=1){s.insert({arr[left]-1,arr[left]});}
        if(arr[left]!=n)s.insert({arr[left],arr[left]+1});
        if(arr[right]!=n){s.insert({arr[right],arr[right]+1});}
        if(arr[right]!=1)s.insert({arr[right]-1,arr[right]});

        for(auto it:s){
            if(index[it.first]>index[it.second]){count--;}

        }

        swap(arr[left],arr[right]);
        swap(index[arr[left]],index[arr[right]]);
        for(auto it:s){

            if(index[it.first]>index[it.second]){count++;}

        }cout<<count<<endl;
        s.clear();

    }

    }


 int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt","r",stdin);
   /* ll n;
    cin>>n;

    for(ll i=1;i<=n;i++){*/
    solve();
      //      }
    }