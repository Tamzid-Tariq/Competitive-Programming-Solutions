/*
Problem: Even Outdegree Edges
Link: https://cses.fi/problemset/task/2179/
Author: Tamzid Tariq
Date: 2026-08-19
Status: Accepted ✓
*/

#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
#define endl '\n'

const ll modular = 1e9 + 7;
const double pi = acos(-1.0);
const ll INF = 1e18;

void solve()
{
    ll num, edges;
    cin >> num >> edges;

    vector<vector<ll>> adj(num);
    vector<pair<ll, ll>> ans;
    for (ll i = 1; i <= edges; i++)
    {
        ll from, to;
        cin >> from >> to;

        adj[--from].push_back(--to);
        adj[to].push_back(from);
    }

    bool pos = 1;
    vector<ll> out(num), visited(num),in(num,INF);

    ll timer=1;
    function<void(ll, ll)> go = [&](ll node, ll par) {
        visited[node]=1;
        in[node]=timer++;
        for(auto it:adj[node])
        {
            if(it==par)continue;
            if(!visited[it])go(it,node);

            // cout<<node+1<<" --> "<<it+1<<" =>"<<in[node]<<" "<<in[it]<<endl;
            if(in[it]<in[node])
            {
                out[node]++;
                ans.push_back({node,it});
            }
        }
        
        if(out[node]&1)
        {
            if(par==-1)pos=0;
            ans.push_back({node,par});
            out[node]++;
        }
        else if(par!=-1)
        {
            out[par]++;
            ans.push_back({par,node});
        }
    };

    for (ll i = 0; i < num; i++)
        if (!visited[i])
            go(i, -1);
        
    
    if (pos)
        for (auto [it, lit] : ans)
        {
            cout << it + 1 << " " << lit + 1 << endl;
        }
    else
        cout << "IMPOSSIBLE\n";
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