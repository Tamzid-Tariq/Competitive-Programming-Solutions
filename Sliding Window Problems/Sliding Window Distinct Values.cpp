/*
Problem: Sliding Window Distinct Values
Link: https://cses.fi/problemset/task/3222/
Author: Tamzid Tariq
Date: 2026-02-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
#define endl '\n';
const ll modular = 1e9 + 7;
const double pi = acos(-1.0);
const ll INF = 1e18;

ll arr[200005];

void solve()
{
    ll num, k;
    cin >> num >> k;

    map<ll,ll>mp;
    for (int i = 1; i <= num; i++)
    {
        cin>>arr[i];
        mp[arr[i]]++;

        if(i>=k)
        {
            cout<<mp.size()<<" ";
            
            mp[arr[i+1-k]]--;

            if(mp[arr[i+1-k]]==0)mp.erase(arr[i+1-k]);
        }
    }

    cout<<endl;
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