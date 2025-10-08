/*
Problem: Josephus Problem I
Link: https://cses.fi/problemset/task/2162/
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
ll number,interval=2,count=0;
cin>>number;

deque<ll>dq;

for(ll i=1;i<=number;i++){
    dq.push_back(i);
}while(dq.size()>1){
    //idea is to visit each and every element one by one
    //if visited element!=interval of killing, then again push that value at the back
    //else pop that element out of the dq element

    ll current=dq.front();
    //visiting the very first element of the deque;
    dq.pop_front();
    //poping this element meaning visiting is done;
    count++;
    if(count==interval){cout<<current<<" ";count=0;}
    if(count%interval!=0){dq.push_back(current);}
}cout<<dq.front()<<endl;
}
 int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //ll n;
    //cin>>n;
    //while(n--){
    solve();
      //        }
    }