/*
Problem: Tasks and Deadlines
Link: https://cses.fi/problemset/task/1630/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int;

using namespace std;

void solve()
{
    ll num;
    cin >> num;
    vector<pair<ll,ll>>vec;
    for(ll i=0;i<num;i++){
        ll duration,deadline;
        cin>>duration>>deadline;
        vec.push_back({duration,deadline});
    }sort(vec.begin(),vec.end());
    ll finish=0,ans=0;
    for(auto it:vec){
        finish+=it.first;
        ans+=it.second-finish;
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