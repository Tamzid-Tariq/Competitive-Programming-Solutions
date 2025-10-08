/*
Problem: Planets and Kingdoms
Link: https://cses.fi/problemset/task/1683/
Author: Tamzid Tariq
Date: 2025-10-08
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

ll num, edges;
vector<vector<ll>> adj, reverseadj;
vector<ll>visited,visitorder,ans;
vector<vector<ll>>allscc;

void dfs(ll node)
{
    visited[node]=1;
    for(auto it:adj[node])
    {
        if(!visited[it])dfs(it);
    }
    visitorder.push_back(node);
}

void dfs2(ll node,ll times)
{
    visited[node]=1;
    ans[node]=times;

    for(auto it:reverseadj[node])
    {
        if(!visited[it])
        dfs2(it,times);
    }
}

void kosaraju()
{
    for(ll i=0;i<num;i++)
    {
        if(!visited[i])dfs(i);
    }

    reverse(visitorder.begin(),visitorder.end());
    visited.assign(num,0);

    ll scc=0;
    for(auto i:visitorder)
    {
        if(!visited[i])
        {
            dfs2(i,++scc);
        }
    }

    cout<<scc<<endl;
    for(auto it:ans)cout<<it<<" ";
}

void solve()
{
    cin >> num >> edges;

    adj.resize(num),reverseadj.resize(num),visited.resize(num);
    allscc.resize(num),ans.resize(num);

    for (ll i = 0; i < edges; i++)
    {
        ll to, from;
        cin >> to >> from;
        to--, from--;

        adj[to].push_back(from);
        reverseadj[from].push_back(to);
    }

    kosaraju();
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