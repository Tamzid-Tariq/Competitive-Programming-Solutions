/*
Problem: Tree Diameter
Link: https://cses.fi/problemset/task/1131/
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

ll num,ans;
vector<vector<ll>>adj;
vector<bool>visited;

ll find_diameter(ll node)
{
    visited[node]=1;

    multiset<ll>ms;      ms.insert(0);

    for(auto it:adj[node])
    {
        if(!visited[it])
        {
            ms.insert(find_diameter(it));
        }
    }
    auto it=ms.rbegin();
    ll maxi=*it;    it--;
    ll second=*it;
    ans=max(ans,maxi+second);

    return maxi+1;
}


void solve()
{
    cin>>num;    adj.resize(num);   visited.resize(num);

    for(ll i=0,to,from;i<num-1;i++)
    {
        cin>>to>>from;      to--,from--;
        adj[to].push_back(from);    adj[from].push_back(to);
    }
    find_diameter(0);
    cout<<ans<<endl;
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