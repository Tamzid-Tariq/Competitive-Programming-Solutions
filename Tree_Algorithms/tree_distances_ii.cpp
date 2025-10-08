/*
Problem: Tree Distances II
Link: https://cses.fi/problemset/task/1133/
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
vector<ll> subtree_siz;
vector<ll> subtree_sum;
vector<ll> ans, par;
void go_recurse(ll node, ll parent)
{
    subtree_siz[node] = 1;
    par[node] = parent;

    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        go_recurse(it, node);
        subtree_siz[node] += subtree_siz[it];
        subtree_sum[node] += subtree_sum[it] + subtree_siz[it];
    }
}

void finding_result(ll node, ll parent)
{
    if (parent != -1)
    {
        ans[node] = ans[parent] -  subtree_siz[node] +(num-subtree_siz[node]);
    }
    
    for (auto it : adj[node])
    {
        if (it != parent)
            finding_result(it, node);
    }
}
// Given Tree
//     1
//     ^
// 2       3
//         ^
//       4   5
// When 2 is the root -> totalsum of 1(6) - distanceof 2 from 1(1) +subtree_siz of 1 (5) - subtree_siz of 2(1);
//         2
//        /
//       1
//        \
    //         3
//         ^
//        4  5
// when 3 is the root
//        3
//     /  |  \         
    //     1  4   5
//    /
//    2

void solve()
{
    cin >> num;
    adj.resize(num);
    subtree_siz.resize(num, 0);
    subtree_sum.resize(num, 0);
    par.resize(num, 0);
    ans.resize(num, 0);

    for (ll i = 1; i < num; i++)
    {
        ll to, from;
        cin >> to >> from;
        to--, from--;

        adj[to].push_back(from);
        adj[from].push_back(to);
    }
    go_recurse(0, -1);
    ans[0] = subtree_sum[0];
    finding_result(0, -1);

    // for (ll i = 0; i < num; i++)
    //     cout << subtree_sum[i] << " ";
    // cout << endl<<endl;
    // for (ll i = 0; i < num; i++)
    //     cout << subtree_siz[i] << " "; cout<<endl;

    for (auto it : ans)
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