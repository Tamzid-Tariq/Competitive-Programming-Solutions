/*
Problem: Distinct Colors
Link: https://cses.fi/problemset/task/1139/
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

void solve()
{
    ll num;
    cin >> num;

    vector<ll> col(num);
    for (auto &it : col)
        cin >> it;

    vector<vector<ll>> adj(num);
    for (ll i = 1; i < num; i++)
    {
        ll from, to;
        cin >> from >> to;

        adj[--from].push_back(--to);
        adj[to].push_back(from);
    }

    vector<ll> ans(num);
    function<set<ll>(ll, ll)> go = [&](ll node, ll par)
    {
        set<ll> me;
        me.insert(col[node]);

        for (auto it : adj[node])
        {
            if (it == par)
                continue;

            auto other = go(it, node);

            if (other.size() > me.size())
                swap(me, other);

            me.merge(other);
        }

        ans[node] = me.size();
        return me;
    };

    go(0, -1);
    for (auto it : ans)
        cout << it << " ";
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