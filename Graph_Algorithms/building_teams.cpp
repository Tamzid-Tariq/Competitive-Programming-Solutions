/*
Problem: Building Teams
Link: https://cses.fi/problemset/task/1668/
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

vector<ll> adjacent[100006];
ll visited[100006];
ll team[100006];

bool dfs(ll vertex, ll color)
{   
    visited[vertex]=1;
    team[vertex]=color;
    for(int child:adjacent[vertex]){
        if(visited[child]==0){
            if(dfs(child,color^1)==false)return false;
        }else{
            if(team[vertex]==team[child])return false;
        }
    }
    
    return true;
}

void solve()
{
    ll pupil, connection;
    cin >> pupil >> connection;
    for (ll i = 0; i < connection; i++)
    {
        ll x, y;
        cin >> x >> y;
        adjacent[x].push_back(y);
        adjacent[y].push_back(x);
    }
    for(ll i=1;i<=pupil;i++){
        if(visited[i]==0){
            bool result=dfs(i,1);
            if(!result){
                cout<<"IMPOSSIBLE\n";
                return;
            }
        }
    }for(ll i=1;i<=pupil;i++)cout<<2-team[i]<<" ";
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