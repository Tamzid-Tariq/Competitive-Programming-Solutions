/*
Problem: Strongly Connected Edges
Link: https://cses.fi/problemset/task/2177/
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
    vector<pair<ll,ll>>ans;
    for (ll i = 1; i <= edges; i++)
    {
        ll from, to;
        cin >> from >> to;
        
        adj[--from].push_back(--to);
        adj[to].push_back(from);

        ans.push_back({from,to});
    }

    vector<ll>in(num,INF),low(num,INF),parent(num);

    bool pos=1;
    ll timer=1;
    function<void(ll,ll)>go=[&](ll node,ll par)
    {
        in[node]=timer++;
        parent[node] = par;
        for(auto it:adj[node])
        {
            if(it==par)continue;

            if(in[it]==INF)
            { 
                go(it,node);
            }

            low[node] = min({low[it],in[it],low[node]});
        }
        if(low[node]>=in[node]+(in[node]==1))pos=0;

        // cout<<node+1<<": "<<in[node]<<" -> "<<low[node]<<endl;
    };

    go(0,-1);

    if(*max_element(in.begin(),in.end())==INF)pos=0;

    if(pos )for(auto [it,lit]:ans)
    {
        if(in[lit]<in[it])swap(it,lit);

        if(parent[lit]!=it)swap(it,lit);

        cout<<it+1<<" "<<lit+1<<endl;
    }
    else cout<<"IMPOSSIBLE\n";
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