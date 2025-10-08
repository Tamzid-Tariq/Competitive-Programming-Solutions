/*
Problem: Sum of Two Values
Link: https://cses.fi/problemset/task/1640/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int ;
using ull=unsigned long long int;
using namespace std;
const ll maxi=1e9+7;



 void solve(){ll asize,sum;
 cin>>asize>>sum;
 vector< pair < ll,ll > >vec(asize);

for(ll i=0;i<asize;i++){
    ll x;
    cin>>x;
    vec[i]={x,i+1};
}
    sort(vec.rbegin(),vec.rend());

 ll start=0,end=asize-1,value=0,ans=0,total=0;
    while(start<end){
    value=vec[start].first + vec[end].first ;
    if(value==sum){cout<<vec[start].second<<" "<<vec[end].second<<endl; ans++; break;}
    else if(value>sum){start++;}
    else if(value<sum){end--;}
}

 if(ans==0)cout<<"IMPOSSIBLE"<<endl;

 }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();

}