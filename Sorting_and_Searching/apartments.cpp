/*
Problem: Apartments
Link: https://cses.fi/problemset/task/1084/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int ;
using ull=unsigned long long int;
using namespace std;
const ll maxi=1e9+7;

bool is_prime(ll x){
    if(x==1){
            return 0;
    }
    for(ll i=2;i*i<=x;++i){
        if(x%i==0)return 0;
        }
         return 1;
                    }

ll smallest_divisor(ll x){
    for(ll i=3;i*i<=x;i++){
        if(x%i==0)return i;
    }
                        }

void solve(){

 ll applicants,apartments,difference;

 cin>>applicants>>apartments>>difference;

    vector<ll>desired;

    vector<ll>possibility;

    for(ll k=0;k<applicants;k++){
        ll x;
        cin>>x;
        desired.push_back(x);
        }

        sort(desired.begin(),desired.end());

    while(apartments--){
        ll y;
        cin>>y;
        possibility.push_back(y);
              }
        sort(possibility.begin(),possibility.end());

    ll count=0;

    for(ll i=0;i<applicants;i++){

            auto itn=lower_bound(possibility.begin(),possibility.end(),(desired[i]-difference));
        ll index=itn-possibility.begin();
            //cout<<possibility[index]<<" "<<desired[i]+difference<<endl;

        if( (itn!=possibility.end())&&(possibility[index]<=(desired[i]+difference) ) ) {
                                    count++;
                                    possibility[index]=LLONG_MIN;}
                                }
        cout<<count<<endl;
}

 int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();

    }