/*
Problem: Tree Distances I
Link: https://cses.fi/problemset/task/1132/
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

ll num;
vector<vector<ll>> adj;
vector<ll> ans;

ll bfs(ll node)
{
    queue<pair<ll,ll>>q;
    vector<ll>visited(num,0);

    ll ret=node,maxi=0;    q.push({ret,maxi});

    while(!q.empty())
    {
        auto [it,lit]=q.front();    q.pop();
        visited[it]=1;
        ans[it]=max(ans[it],lit);
        if(lit>maxi)
        {
            maxi=lit;
            ret=it;
        }
        for(auto child:adj[it])
        {
            if(visited[child])continue;
            q.push({child,lit+1});
        }
    }
    return ret;
}

void solve()
{
    
    cin >> num;
    adj.resize(num);
    ans.resize(num);

    for (ll i = 1; i < num; i++)
    {
        ll to, from;
        cin >> to >> from;
        to--, from--;

        adj[to].push_back(from);
        adj[from].push_back(to);
    }

    ll endpoint1=bfs(0);
    ll endpoint2=bfs(endpoint1);
    ll result=bfs(endpoint2);

    for(auto it:ans)cout<<it<<" ";
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