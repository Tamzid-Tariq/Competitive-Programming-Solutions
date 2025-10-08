/*
Problem: Longest Flight Route
Link: https://cses.fi/problemset/task/1680/
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
const ll INF = 1e18;

ll vertex, edges;
vector<vector<ll>> adj(100005);

ll ans[100005];

ll go_recurse(ll pos)
{
    if (pos == vertex)
        return ans[pos] = 1;
    if (ans[pos] != -1)
        return ans[pos];

    ll ret = -INF;

    for (auto it : adj[pos])
    {
        ret = max(ret, 1 + go_recurse(it));
    }
    return ans[pos] = ret;
}
vector<ll> path;

void find_ans(ll pos)
{
    if (pos == -1)
        return;
    path.push_back(pos);
    if (pos == vertex)
        return;
    ll next = -1;
    ll maxi = 0;
    for (auto it : adj[pos])
    {
        if (go_recurse(it) > maxi)
        {
            maxi = go_recurse(it);
            next = it;
        }
    }
    // cout<<next<<endl;
    find_ans(next);
}

void solve()
{
    cin >> vertex >> edges;

    for (ll i = 0; i < edges; i++)
    {
        ll from, to;
        cin >> from >> to;
        adj[from].push_back(to);
    }

    memset(ans, -1, sizeof ans);
    ll result = go_recurse(1);
    find_ans(1);
    if (path.size()== 1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    cout << result << endl;
    
    for (auto it : path)
        cout << it << " ";
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