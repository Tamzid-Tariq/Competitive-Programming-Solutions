/*
Problem: Factory Machines
Link: https://cses.fi/problemset/task/1620/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int;

using namespace std;
vector<ll>vec;

ll binarysearch(ll x){
    ll ans=0;
    for(ll i=0;i<vec.size();i++){
        ans+=min(x/vec[i],(ll)1e9);
    }
    return ans;
}
void solve()
{
    ll num,need;
    cin >> num >> need;
    while(num--){
        ll x;
        cin>>x;
        vec.push_back(x);
    }
    ll low=1,high=1e18,mid=(low+high)/2,ans=high; 
    while(low<=high){
        ll mid=(low+high)/2;
        if(binarysearch(mid)>=need){high=mid-1;
        ans=min(ans,mid);}
        else low=mid+1;
    }cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    n = 1;
    // cin >> n;
    for (ll i = 1; i <= n; ++i)
    {
        solve();
    }
    return 0;
}