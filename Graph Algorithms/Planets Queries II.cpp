/*
Problem: Planets Queries II
Link: https://cses.fi/problemset/task/1160/
Author: Tamzid Tariq
Date: 2025-12-07
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
    ll num, query;
    cin >> num >> query;

    vector<vector<ll>> forward(num, vector<ll>(25));

    for (ll i = 0; i < num; i++)
    {
        ll to;
        cin >> to;

        forward[i][0] = (--to);
    }

    for (ll j = 1; j < 25; j++)
    {
        for (ll i = 0; i < num; i++)
            forward[i][j] = forward[forward[i][j - 1]][j - 1];
    }

    vector<ll> visited(num), height(num), componentid(num);

    ll current = 1;

    function<void(ll)> go = [&](ll node)
    {
        if (visited[node])
        {
            if (!componentid[node])
                componentid[node] = current++;

            return;
        }

        visited[node] = 1;
        go(forward[node][0]);
        height[node] = height[forward[node][0]] + 1;
        componentid[node] = componentid[forward[node][0]];
    };

    for (ll i = 0; i < num; i++)
        if (!visited[i])
            go(i);

    vector<pair<ll, ll>> cycle(current);

    visited.assign(num, 0);
    vector<ll> done(current + 1, 0);

    function<void(ll)> getcycle = [&](ll node)
    {
        visited[node] = 1;

        ll nxt = forward[node][0];
        if (visited[nxt])
        {
            cycle[componentid[node]] = {node, nxt};
            done[componentid[node]] = 1;
            return;
        }

        getcycle(nxt);
    };

    for (ll i = 0; i < num; i++)
        if (!visited[i] && !done[componentid[i]])
            getcycle(i);

    function<ll(ll, ll)> ahead = [&](ll node, ll diff)
    {
        if (!diff)
            return node;

        for (ll j = 20; j >= 0; j--)
            if (diff & (1LL << j))
                return ahead(forward[node][j], diff - (1LL << j));
    };

    while (query--)
    {
        ll from, to;
        cin >> from >> to;
        --from, --to;

        if (from == to)
        {
            cout << 0 << endl;
            continue;
        }

        if (componentid[from] != componentid[to])
        {
            cout << -1 << endl;
        }

        else
        {
            auto [x, y] = cycle[componentid[from]];

            ll start = height[x], end = height[y];

            if (start > end)
                swap(x, y), swap(start, end);

            ll dist1 = height[from], dist2 = height[to], siz = end - start + 1;

            if (dist2 < dist1)
            {
                if (ahead(from, dist1 - dist2) == to)
                {
                    cout << dist1 - dist2 << endl;
                }

                else if(ahead(from,dist1-dist2 + siz) == to)
                {
                    cout<<dist1-dist2 + siz<<endl;
                    
                }
                else
                {
                    cout << -1 << endl;
                }
            }
            else
            {
                if (max(dist1, dist2) <= end && min(dist1, dist2) >= start)
                {
                    // cout<<start<<" "<<end<<" "<<dist2<<" "<<dist1<<endl;
                    ll ans = (end - dist2) + (dist1 + 1 - start);
 
                    if (ahead(from, ans) == to)
                    {
                        cout << ans << endl;
                    }
                    else
                        cout << -1 << endl;
                }
                else
                {
                    cout << -1 << endl;
                }
            }
        }
    }

    // for (auto it : height)
    //     cout << it << " ";
    // cout << endl;

    // for (auto it : componentid)
    //     cout << it << " ";
    // cout << endl;
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