/*
Problem: Tree Matching
Link: https://cses.fi/problemset/task/1130/
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

ll ans[200005][2];

ll go_recurse(ll node, ll parent, ll taken)
{
    if (ans[node][taken] != -1)
        return ans[node][taken];

    ll ret = 0;
    vector<pair<ll, ll>> all;

    for (auto it : adj[node])
    {
        if (it != parent)
        {
            if (!taken)
                ret += max(go_recurse(it, node, 1), go_recurse(it, node, 0));

            else
            {
                all.push_back({go_recurse(it, node, 0), go_recurse(it, node, 1)});
            }
        }
    }

    // cout<<node+1<<" "<<taken<<" "<<ret<<endl;
    if (taken && !all.empty())
    {
        // cout<<node+1<<" "<<got<<endl;
        sort(all.begin(), all.end());
        bool used = 0;

        for (ll i = 0; i < all.size(); i++)
        {
            if (all[i].first >= all[i].second && !used)
            {
                used = 1;
                ret += 1 + all[i].first;
            }
            else
                ret += max(all[i].first, all[i].second);
        }

        if (!used)
        {
            ret -= all[0].second;
            ret += all[0].first + 1;
        }
    }

    return ans[node][taken] = ret;
}

void solve()
{
    cin >> num;
    adj.resize(num);

    for (ll i = 1; i < num; i++)
    {
        ll from, to;
        cin >> from >> to;
        from--, to--;

        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    memset(ans, -1LL, sizeof(ans));

    cout << max(go_recurse(0, -1, 1), go_recurse(0, -1, 0)) << endl;

    // for(ll i=0;i<num;i++)
    // {
    //     cout<<i+1<<" "<<ans[i][0]<<" "<<ans[i][1]<<endl;
    // }
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