/*
Problem: Course Schedule II
Link: https://cses.fi/problemset/task/1757/
Author: Tamzid Tariq
Date: 2026-08-19
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

void solve()
{
    ll num, edges;
    cin >> num >> edges;

    vector<vector<ll>> adj(num); 
    vector<ll>indegree(num);
    for (ll i = 1; i <= edges; i++)
    {
        ll from, to;
        cin >> from >> to;
        
        swap(from,to);
        adj[--from].push_back(--to);
        indegree[to]++;
    }

    set<ll>avail;
    for(ll i=0;i<num;i++)if(!indegree[i])avail.insert(i);

    vector<ll>ans;
    while(!avail.empty())
    {
        auto node = *avail.rbegin();
        avail.erase(avail.find(node));

        ans.push_back(node+1);
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(!indegree[it])avail.insert(it);
        }
    }

    reverse(ans.begin(),ans.end());
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