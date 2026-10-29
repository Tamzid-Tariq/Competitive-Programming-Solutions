/*
Problem: Hamiltonian Flights
Link: https://cses.fi/problemset/task/1690/
Author: Tamzid Tariq
Date: 2025-11-26
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

ll ans[20][1LL << 20];
ll times[20][20];

ll add(ll val1, ll val2)
{
    ll result = (val1 % modular) + (val2 % modular);
    return result % modular;
}

ll multiply(ll val1, ll val2)
{
    ll result = (val1 % modular) * (val2 % modular);
    return result % modular;
}

void solve()
{
    ll num, edges;
    cin >> num >> edges;

    // vector<vector<ll>> adj(num);

    for (ll i = 0; i < edges; i++)
    {
        ll from, to;
        cin >> from >> to;

        times[--from][--to]++;
        // adj[--from].push_back(--to);
    }

    memset(ans, -1, sizeof(ans));

    function<ll(ll, ll)> go = [&](ll mask, ll where)
    {
        if (mask == (1LL << num - 1))
        {
            return times[where][num - 1];
        }

        if (ans[where][mask] != -1)
            return ans[where][mask];

        ll ret = 0LL;

        for (int i = 0; i < num - 1; i++)
        {
            if ((mask & (1LL << i)) && (times[where][i]))
            {
                ret = add(ret, multiply(times[where][i], go((mask ^ (1LL << i)), i)));
            }
        }

        return ans[where][mask] = ret;
    };

    cout << go((1LL << num) - 2, 0) << endl;
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