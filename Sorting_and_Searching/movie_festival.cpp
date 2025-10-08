/*
Problem: Movie Festival
Link: https://cses.fi/problemset/task/1629/
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
     ll x;
     cin>>x;
vector<pair<ll,ll>>vec;
//vec[0]={-1,-1};
ll endtime=-1;
//Idea is to select a next possible event that ends as early as possible;
for(ll i=0;i<x;i++){ll first,second;
        cin>>second>>first;
        vec.push_back({first,second});
}
    sort(vec.begin(),vec.end());
    ll count=0;
for(ll j=0;j<x;j++){
    if(endtime<=vec[j].second){count++;
    endtime=vec[j].first;
    //cout<<"endtime "<<endtime<<endl;
    }
 }
 cout<<count<<endl;
 }


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();

}