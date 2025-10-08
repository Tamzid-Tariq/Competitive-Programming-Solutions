/*
Problem: Course Schedule
Link: https://cses.fi/problemset/task/1679/
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
    ll num, edges;
    cin >> num >> edges;

    vector<vector<ll>> adj;
    adj.resize(num);
    vector<ll> indegree;
    indegree.resize(num);

    for (ll i = 0; i < edges; i++)
    {
        ll from, to;
        cin >> to >> from;
        from--, to--;

        adj[from].push_back(to);
        adj[to].push_back(from);
        indegree[from]++;
    }

    stack<ll> st;
    vector<ll> topsort;

    for (ll i = 0; i < num; i++)
    {
        if (!indegree[i])
        {
            st.push(i);
        }
    }

    while (!st.empty())
    {
        ll top = st.top();
        st.pop();
        topsort.push_back(top + 1);

        for (auto it : adj[top])
        {
            indegree[it]--;
            if (!indegree[it])
                st.push(it);
        }
    }

    if (topsort.size() != num)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
        for (auto it : topsort)
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