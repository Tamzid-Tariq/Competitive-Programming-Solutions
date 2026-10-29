/*
Problem: Acyclic Graph Edges
Link: https://cses.fi/problemset/task/1756/
Author: Tamzid Tariq
Date: 2026-08-19
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

    vector<vector<ll>> adj(num);
    for (ll i = 1; i <= edges; i++)
    {
        ll from, to;
        cin >> from >> to;

        cout<<max(from,to)<<" "<<min(from,to)<<endl;
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