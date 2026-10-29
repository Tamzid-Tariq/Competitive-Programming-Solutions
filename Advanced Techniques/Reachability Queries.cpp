/*
Problem: Reachability Queries
Link: https://cses.fi/problemset/task/2143/
Author: Tamzid Tariq
Date: 2026-02-17
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
vector<ll> visited, visitorder, ans;
vector<vector<ll>> allscc;
ll scc = 0;
bitset<50004> all[50004];

void dfs(ll node)
{
    visited[node] = 1;
    for (auto it : adj[node])
    {
        if (!visited[it])
            dfs(it);
    }
    visitorder.push_back(node);
}

void dfs2(ll node, ll times)
{
    visited[node] = 1;
    ans[node] = times - 1;
    allscc[times - 1].push_back(node);

    for (auto it : reverseadj[node])
    {
        if (!visited[it])
            dfs2(it, times);
    }
}

void kosaraju()
{
    for (ll i = 0; i < num; i++)
    {
        if (!visited[i])
            dfs(i);
    }

    reverse(visitorder.begin(), visitorder.end());
    visited.assign(num, 0);

    for (auto i : visitorder)
    {
        if (!visited[i])
        {
            dfs2(i, ++scc);
        }
    }

    // cout << scc << endl;
    // for (auto it : ans)
    //     cout << it + 1 << " ";
    // cout << endl;

    vector<vector<ll>> dag(scc);

    for (ll i = 0; i < scc; i++)
    {
        // cout << i + 1 << ": ";
        for (auto it : allscc[i])
        {
            all[i][it] = 1;

            for (auto lit : adj[it])
            {
                if (ans[it] != ans[lit])
                    dag[ans[it]].push_back(ans[lit]);
            }
        }
    }

    visited.assign(scc, 0);
    function<void(ll)> go = [&](ll comp)
    {
        visited[comp] = 1;

        for (auto it : dag[comp])
        {
            if (!visited[it])
                go(it);

            all[comp] |= all[it];
        }
    };

    for (ll i = 0; i < scc; i++)
        if (!visited[i])
            go(i);
}

void solve()
{
    ll queries;
    cin >> num >> edges >> queries;
    adj.resize(num);
    reverseadj.resize(num);

    for (ll i = 0; i < edges; i++)
    {
        ll from, to;
        cin >> from >> to;

        adj[--from].push_back(--to);
        reverseadj[to].push_back(from);
    }

    visited.resize(num);
    allscc.resize(num);
    ans.resize(num);
    kosaraju();

    for (ll i = 0; i < queries; i++)
    {
        ll from, to;
        cin >> from >> to;

        from--;
        to--;

        cout << (all[ans[from]][to] ? "YES\n" : "NO\n");
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