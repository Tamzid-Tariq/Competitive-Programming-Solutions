/*
Problem: Traffic Lights
Link: https://cses.fi/problemset/task/1163/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int ;
using ull=unsigned long long int;
using namespace std;
const ll maxi=1e9+7;

bool cmp(pair<ll,ll>&a, pair<ll,ll>&b){
return a.second<b.second;}

void sort(map<ll,ll>& M){
vector< pair<ll,ll> >A;

for(auto& it : M){
A.push_back(it); }

sort(A.rbegin(),A.rend(),cmp);

//auto it=A.begin();
cout<< A[0].second<<endl;
}

void solve(){
ll number;
cin>>number;
multiset<ll>numbers;
multiset<ll>answer;
numbers.insert(0);
numbers.insert(number);
answer.insert(number-0);
ll cases;
cin>>cases;
while(cases--){
    ll i;
    cin>>i;
    numbers.insert(i);

    auto iu=numbers.find(i);
    //cout<<*iu<<endl;
    //cout<<*(--iu)<<*(iu)<<*(++iu)<<endl;

    ll value=*(++iu);
    ll value1=*(iu)-i;

    --iu;--iu;
    ll value2=i-*(iu);
    value-=*(iu);
    //cout<<value<<" "<<value1<<" "<<value2<<endl;
    //cout<<value;/*
    auto x=answer.find(value);
    answer.erase(x);
    answer.insert(value1);
    answer.insert(value2);
    auto k=answer.rbegin();
    cout<<*k<<" ";//*/
    }
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