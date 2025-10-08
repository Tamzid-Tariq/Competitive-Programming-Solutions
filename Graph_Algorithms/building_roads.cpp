/*
Problem: Building Roads
Link: https://cses.fi/problemset/task/1666/
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

ll num,edges;
vector<vector<ll>>adj;
vector<ll>visited;

void dfs(ll node)
{
    visited[node]=true;

    for(auto it:adj[node])
    {
        if(!visited[it])
        {
            dfs(it);
        }
    }
}

void solve()
{
    
    cin>>num>>edges;
    adj.resize(num);
    visited.resize(num,0);

    for(ll i=0;i<edges;i++)
    {
        ll to,from;
        cin>>to>>from;
        to--,from--;
        adj[to].push_back(from);
        adj[from].push_back(to);
    }
    vector<ll>ans;

    for(ll i=0;i<num;i++)
    {
        if(!visited[i])
        {
            dfs(i);
            ans.push_back(i+1);
        }
    }
    cout<<ans.size()-1<<endl;

    for(ll i=1;i<ans.size();i++)
    {
        cout<<ans[0]<<" "<<ans[i]<<endl;
    }
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