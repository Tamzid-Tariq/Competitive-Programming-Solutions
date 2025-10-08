/*
Problem: Concert Tickets
Link: https://cses.fi/problemset/task/1091/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int ;
using ull=unsigned long long int;
using namespace std;
const ll maxi=1e9+7;



 void solve(){ll tickets,lines;
 cin>>tickets>>lines;
queue<ll>sari;
multiset<ll>vec;

for(ll i=0;i<tickets;i++){
        ll d;
        cin>>d;
        vec.insert(d);
}
    //sort(vec.begin(),vec.end());

for(ll j=0;j<lines;j++){
    ll cust,ans=0;
    cin>>cust;
    auto index=vec.upper_bound(cust); //cout<<index<<" ";

    if(index==vec.begin()){cout<<"-1"<<endl;}
    else{index--;
    cout<<*index<<endl;
    vec.erase(index);
    }




/*
    for(ll i=index;i>=0;i--){
        if(vec[i]<=cust && vec[i]!=0){cout<<vec[i]<<endl; vec[i]=0;ans++;break;}
    }
*/
//if(ans==0){cout<<"-1"<<endl;}
    /*
    ll index=(lower_bound(vec.begin(),vec.end(),cust))-vec.begin();
    //cout<<index<<endl;
    if(index!=tickets){
    (vec[index]==cust)?((ans=vec[index]) && (vec[index]=0)):((ans=vec[index+1])&&(vec[index+1]=0));
    (ans==0)?(cout<<"-1"<<endl):(cout<<ans<<endl);}
    else cout<<"-1"<<endl;*/
}

 //if(ans==0)cout<<"IMPOSSIBLE"<<endl;

 }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();

}