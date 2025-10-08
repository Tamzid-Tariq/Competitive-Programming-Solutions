/*
Problem: Playlist
Link: https://cses.fi/problemset/task/1141/
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
ll number;
cin>>number;
vector<ll>vec;
map<ll,ll>mp;
for(ll i=0;i<number;i++){
ll x;
cin>>x;
vec.push_back(x);
mp[x]=-1;}
//start=0,end=1     start=1,end=0, start=1 end=1
// end-start end-start+1 end-start-1
ll start=0,end=0,
count=0,ans=0;

for(end=0;end<number;end++){

if(mp[vec[end]]<start){mp[vec[end]]=end;}

else{ans=max(ans,end-start);
start=mp[vec[end]] +1;
mp[vec[end]]=end;}
ans=max(ans,end-start+1);
    }
    cout<<ans<<endl;

}



 int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //ll n;
    //cin>>n;
    //while(n--){
    solve();
      //       }
}