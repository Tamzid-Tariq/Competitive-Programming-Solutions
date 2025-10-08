/*
Problem: Restaurant Customers
Link: https://cses.fi/problemset/task/1619/
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

   ll a;
   cin>>a;
   vector<pair<ll,ll>>vec(2*a);
   ll max=0;
   for(ll i=0;i<2*a;i+=2){ ll x,y;
   cin>>x>>y;
   vec[i]={x,+1};
   vec[i+1]={y,-1};
   }
   sort(vec.begin(),vec.end());
   ll count=0;
   for(ll start=0;start<2*a;start++){
    count+=vec[start].second;
    (count>max)?(max=count):0;
                                    }

   cout<<max<<endl;

}
 int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();

    }