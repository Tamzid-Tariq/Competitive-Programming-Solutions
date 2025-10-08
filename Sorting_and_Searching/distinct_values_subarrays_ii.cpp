/*
Problem: Distinct Values Subarrays II
Link: https://cses.fi/problemset/task/2428/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int;
using ull = unsigned long long int;
using namespace std;
const ll modular = 1e9 + 7;
const double pi = 22 / 7;

void solve()
{
    ll num, maxi;
    cin >> num >> maxi;
    vector<ll> vec;
    vec.push_back(0);

    set<ll> s;

    ll ans = 0;

    ll start = 1;
    ll end = 1;

    map<ll, ll> mp;

    for (end = 1; end <= num; end++)
    {
        ll x;
        cin >> x;
        vec.push_back(x);
        s.insert(x);
        mp[x]++;
        if(s.size()<=maxi){
            ans+=end-start+1;
        }
        else{
            for(ll i=start;i<=end;i++){
                mp[vec[i]]--;
                if(mp[vec[i]]==0){s.erase(vec[i]);
                start=i+1;
                ans+=end-start+1;
                break;
                }
            }
        }
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
            // cout << "Case " << i << ": ";
            solve();
        }
        return 0;
    }