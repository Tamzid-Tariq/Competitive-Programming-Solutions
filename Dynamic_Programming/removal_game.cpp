/*
Problem: Removal Game
Link: https://cses.fi/problemset/task/1097/
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

ll num;
ll val[5006];
ll ans[5006][5006];
bool visited[5006][5006];

ll go_recurse(ll start, ll end, bool turn)
{
    if (start > end)
        return 0;

    if (start == end)
    {
        if (turn)
            return ans[start][end] = val[start];
        else
            return ans[start][end] = 0;
    }

    if (visited[start][end])
    {
        return ans[start][end];
    }

    ll val1 = LLONG_MIN;
    if (turn)
    {
        val1 = val[start] + go_recurse(start + 1, end, 0);
        ll val2 = val[end] + go_recurse(start, end - 1, 0);
        val1 = max(val1, val2);
    }
    else
    {
        val1 = go_recurse(start + 1, end, 1);
        val1 = min(val1, go_recurse(start, end - 1, 1));
    }
    // cout<<start<<" "<<end<<" "<<turn<<" "<<val1<<endl;
    visited[start][end] = true;
    return ans[start][end] = val1;
}

void solve()
{
    cin >> num;

    for (ll i = 0; i < num; i++)
    {
        cin >> val[i];
    }
    cout << go_recurse(0, num - 1, 1) << endl;
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