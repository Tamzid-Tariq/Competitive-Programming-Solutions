/*
Problem: Planets Cycles
Link: https://cses.fi/problemset/task/1751/
Author: Tamzid Tariq
Date: 2025-10-08
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
    ll num;
    cin >> num;

    vector<ll> adj(num);
    for (auto &it : adj)
    {
        cin >> it;
        it--;
    }

    ll cycle = 0;
    vector<ll> visited(num), cyclic(num), parent(num, -1), len(num + 1);

    function<void(ll)> go = [&](ll node)
    {
        visited[node] = cycle;

        if (visited[adj[node]])
        {
            if (visited[adj[node]] == cycle)
            {
                ll times = 1;
                cyclic[node] = cycle;
                ll now = node;

                while (now != adj[node])
                {
                    now = parent[now];
                    cyclic[now] = cycle;
                    times++;
                }
                len[cycle] = (times);
            }
        }
        else
        {
            parent[adj[node]] = node;
            go(adj[node]);
        }
    };

    vector<ll> ans(num);

    for (ll i = 0; i < num; i++)
    {
        if (!visited[i])
        {
            cycle++;
            parent[i] = i;
            go(i);
        }
    }

    function<ll(ll)> what = [&](ll node)
    {
        if (ans[node])
            return ans[node];
        return ans[node] = 1LL + what(adj[node]);
    };

    for (ll i = 0; i < num; i++)
    {
        if (cyclic[i])
            ans[i] = len[cyclic[i]];
    }

    for (ll i = 0; i < num; i++)
        cout << what(i) << " ";
    cout << endl;
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