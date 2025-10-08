/*
Problem: Apple Division
Link: https://cses.fi/problemset/task/1623/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int;

using ull = unsigned long long int;

using namespace std;

const ll modular = 1e9 + 7;

const double pi = 22 / 7;

const ll INF = LLONG_MAX;

ll vertex;

vector<ll> adj[300005];

vector<ll> dist;

vector<bool> vis;

set<ll> s;

ll bfs(ll start, ll len)

{

    vis.assign(vertex + 1, 0);

    dist.assign(vertex + 1, 0);

    queue<ll> q;

    q.push(start);

    s.insert(start);

    dist[start] = 0;

    ll res = 1;

    vis[start] = 1;

    while (!q.empty())

    {

        ll curr = q.front();

        if (dist[curr] == len)

            return res;

        q.pop();

        for (auto it : adj[curr])

        {

            if (!vis[it])

            {

                q.push(it);

                dist[it] = dist[curr] + 1;

                res++;

                vis[it] = 1;

                s.insert(it);
            }
        }
    }

    return res;
}

void solve()

{

    ll n;

    cin >> n;

    ll x = n;

    vector<ll> vec;

    while (n--)

    {

        ll num;

        cin >> num;

        vec.push_back(num);
    }

    ll min_difference = LLONG_MAX;

    for (ll i = 1; i < (1 << x); i++)

    {

        ll sum1 = 0;

        ll sum2 = 0;

        bitset<32> bit(i);

        for (ll start = 0; start < x; start++)

        {

            if (bit[start])

            {

                sum1 += vec[start];
            }

            else

                sum2 += vec[start];
        }

        min_difference = min(min_difference, (abs(sum1 - sum2)));
    }

    cout << min_difference << endl;
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