/*
Problem: Ferris Wheel
Link: https://cses.fi/problemset/task/1090/
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
 ll numbers,max_weight;
 cin>>numbers>>max_weight;


 vector<ll>vec;
 for(ll i=0;i<numbers;i++){
    ll x;
    cin>>x;
    vec.push_back(x);
                        }
    sort(vec.begin(),vec.end());

   ll count=0;
   ll start=0,end=numbers-1;

   while(start<=end){
    if((vec[start]+vec[end])<=max_weight){
        count++;
        start++; end--;
    }
    else{end--;
    count++;}
    }


    cout<<count<<endl;
    }


 int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();

    }