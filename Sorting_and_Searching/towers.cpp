/*
Problem: Towers
Link: https://cses.fi/problemset/task/1073/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int ;
using ull=unsigned long long int;
using namespace std;
const ll maxi=1e9+7;

vector<ll>PowerOfTen(19,1);

void solve(){
   ll numbers;
   cin>>numbers;
   multiset<ll>multitalent;
   while(numbers--){ ll x;
   cin>>x;
   multitalent.insert(x);
   auto it=multitalent.upper_bound(x);
   if(it!=multitalent.end()){
      multitalent.erase(it);
   }

   }cout<<multitalent.size()<<endl;
}

 int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    for(ll i=1;i<19;i++){
      PowerOfTen[i]=PowerOfTen[i-1]*10;
      //0 -1; 1-10; 2-100; 3-1000; 4-10000; 
    }
   // ll n;
    //cin>>n;
    //while(n--){
    solve();
      //        }
    }