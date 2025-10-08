/*
Problem: Flight Routes Check
Link: https://cses.fi/problemset/task/1682/
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

vector<vector<ll>> adj1;
vector<vector<ll>> adj2;
vector<bool> vis;

void dfs(ll node, ll type, stack<ll> &s)
{
    // cout<<node<<" ";
    vis[node] = true;
    vector<vector<ll>> &adj = (type) ? (adj2) : (adj1);
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, type, s);
    }
    if (!type)
        (s.push(node));
}

void solve()
{
    ll num, edges;
    cin >> num >> edges;

    adj1.resize(num);
    adj2.resize(num);
    vis.assign(num, false);

    for (ll i = 0; i < edges; i++)
    {
        ll to, from;
        cin >> to >> from;
        to--, from--;
        adj1[to].push_back(from);
        adj2[from].push_back(to);
    }

    stack<ll> s;
    // s.push(0);
    dfs(0, 0, s);
    // cout<<endl;
    // while(!s.empty())
    // {
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    ll last = -1;
    for (ll i = 0; i < num; i++)
    {
        if (!vis[i])
        {
            if (last == -1)
                last = i;
            else
            {
                cout << "NO\n";
                cout << last + 1 << " " << i + 1 << endl;
                return;
            }
        }
        last = i;
        vis[i] = false;
    }
    last = -1;
    dfs(s.top(), 1, s);
    while (!s.empty())
    {
        if (!vis[s.top()])
        {
            if (last == -1)
                last = s.top();
            else
            {
                cout << "NO\n";
                cout << s.top() + 1 << " " << last + 1 << endl;
                return;
            }
        }
        last = s.top();
        s.pop();
    }
    cout << "YES\n";
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