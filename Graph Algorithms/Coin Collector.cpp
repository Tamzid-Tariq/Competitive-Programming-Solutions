/*
Problem: Coin Collector
Link: https://cses.fi/problemset/task/1686/
Author: Tamzid Tariq
Date: 2025-10-26
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

const ll N = 100005;

// ll num, edges;
// vector<vector<ll>> adj(N), reverseadj(N);

void solve()
{
    ll num, edges;
    cin >> num >> edges;

    vector<ll> vec(num);
    for (auto &it : vec)
        cin >> it;

    vector<vector<ll>> adj(num), reverseadj(num);
    for (ll i = 0; i < edges; i++)
    {
        ll from, to;
        cin >> from >> to;

        adj[--from].push_back(--to);
        reverseadj[to].push_back(from);
    }

    vector<ll> visited(num), visitorder, ans(num);
    vector<vector<ll>> allscc(num);

    function<void(ll)> dfs = [&](ll node)
    {
        visited[node] = 1;
        for (auto it : adj[node])
        {
            if (!visited[it])
                dfs(it);
        }
        visitorder.push_back(node);
    };

    function<void(ll, ll)> dfs2 = [&](ll node, ll times)
    {
        visited[node] = 1;
        ans[node] = times;
        allscc[times - 1].push_back(node);

        for (auto it : reverseadj[node])
        {
            if (!visited[it])
                dfs2(it, times);
        }
    };

    for (ll i = 0; i < num; i++)
    {
        if (!visited[i])
            dfs(i);
    }

    reverse(visitorder.begin(), visitorder.end());
    visited.assign(num, 0);

    ll scc = 0;
    for (auto i : visitorder)
    {
        if (!visited[i])
        {
            dfs2(i, ++scc);
        }
    }

    // cout << scc << endl;
    // for (auto it : ans)
    //     cout << it << " ";

    vector<ll> totalcoins(scc);

    for (ll i = 0; i < scc; i++)
    {
        for (auto it : allscc[i])
            totalcoins[i] += vec[it];

        // cout<<totalcoins[i]<<endl;
    }
    vector<vector<ll>> sccadj(scc);

    for (ll i = 0; i < num; i++)
    {
        for (auto it : adj[i])
        {
            if (ans[it] != ans[i])
            {
                // cout << i + 1 << " -> " << it + 1 << endl;
                sccadj[ans[i] - 1].push_back(ans[it] - 1);
            }
        }
    }

    vector<ll> dp(scc, -1), visitedscc(scc);

    function<ll(ll)> go = [&](ll sccnum)
    {
        if (dp[sccnum] != -1)
            return dp[sccnum];

        ll ret = totalcoins[sccnum];

        for (auto it : sccadj[sccnum])
        {
            ret = max(ret, totalcoins[sccnum] + go(it));
        }

        return dp[sccnum] = ret;
    };

    ll result = *max_element(totalcoins.begin(), totalcoins.end());
    for (ll i = 0; i < scc; i++)
    {
        result = max(result, go(i));
    }

    cout << result << endl;
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