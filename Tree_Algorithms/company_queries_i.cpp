/*
Problem: Company Queries I
Link: https://cses.fi/problemset/task/1687/
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

vector<vector<ll>> adj;
vector<ll> depth;
ll parent[30][200005];

void assign_depth(ll node, ll val)
{
    depth[node] = val;

    for (auto it : adj[node])
    {
        assign_depth(it, val + 1);
    }
}

void assign_parent(ll node)
{
    if (node)
    {
        for (ll i = 1; i < 30; i++)
        {
            parent[i][node] = parent[i - 1][parent[i - 1][node]];
        }
    }
    for (auto it : adj[node])
    {
        assign_parent(it);
    }
}

ll find_parent(ll node, ll val)
{
    if (!val || node==-1)
        return node;

    ll times = 0, temp = val;

    while (temp / 2)
    {
        temp /= 2;
        times++;
    }
    // cout<<val<<" "<<times<<" "<<val-(1LL<<times)<<endl;
    return find_parent(parent[times][node], val - (1LL << times));
}
void solve()
{
    ll num, query;
    cin >> num >> query;
    adj.resize(num);// depth.resize(num, 0);

    memset(parent, -1LL, sizeof(parent));

    for (ll i = 1; i < num; i++)
    {
        ll par = 0;
        cin >> par;
        par--;
        parent[0][i] = par;
        adj[par].push_back(i);
    }
    // assign_depth(0, 0);
    // for(ll i=0;i<num;i++)cout<<depth[i]<<" ";
    assign_parent(0);

    while (query--)
    {
        ll node, level;
        cin >> node >> level;
        node--;
        ll ans = find_parent(node, level);
        if (ans != -1)
            ans++;
        cout << ans << endl;
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