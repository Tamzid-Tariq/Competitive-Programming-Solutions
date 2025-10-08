/*
Problem: Subordinates
Link: https://cses.fi/problemset/task/1674/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
const ll modular = 1e9 + 7;
const double pi = acos(-1.0);
const ll INF = 10000000000LL;

vector<ll>ans;
vector<vector<ll>>adj;
ll num;
vector<ll>visited;

ll go_recurse(ll node)
{
    ll ret=0;
    for(auto it:adj[node])
    {
        ret+=1+go_recurse(it);
    }
    return ans[node]=ret;
}

void solve()
{
    cin>>num;

    ans.resize(num); ans.assign(num,0LL);
    visited.resize(num); visited.assign(num,0);
    adj.resize(num);

    for(ll i=1;i<num;i++)
    {
        ll j;   cin>>j; j--;
        adj[j].push_back(i);
    }    

    go_recurse(0);
    for(auto it:ans)cout<<it<<" ";
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