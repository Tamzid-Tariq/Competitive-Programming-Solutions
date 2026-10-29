/*
Problem: Movie Festival Queries
Link: https://cses.fi/problemset/task/1664/
Author: Tamzid Tariq
Date: 2025-12-10
Status: Accepted ✓
*/

#include <bits/stdc++.h>

typedef int ll;
using namespace std;
#define endl '\n';

const ll N = 1000000;
ll nxt[19][N+2];

void solve()
{
    ll num, queries;
    cin >> num >> queries;

    vector<pair<ll, ll>> vec(num), query(queries);

    for (auto &[it, lit] : vec)
    {
        cin >> it >> lit;
    }

    for (ll i = 0; i <= N; i++)
        nxt[0][i] = N+1;

    for (auto [it, lit] : vec)
    {
        nxt[0][it] = min(nxt[0][it], lit);
    }

    for(ll i=N-1;i>=1;i--)nxt[0][i]=min(nxt[0][i],nxt[0][i+1]);

    for (ll i = 1; i < 19; i++)
    {
        for (ll j = 1; j <=N; j++)
            nxt[i][j] = nxt[i-1][nxt[i-1][j]];
    }

    function<ll(ll, ll)> who = [&](ll start, ll times)
    {
        for (ll i = 0; i < 19 && ((1LL << i) <= times); i++)
            if (times & (1LL << i))
            {
                start = nxt[i][start];
            }
        return start;
    };

    for (auto &[it, lit] : query)
    {
        cin>>it>>lit;

        ll lo = 1, hi = num, ans = 0;

        while (lo <= hi)
        {
            ll mid = (lo + hi) >> 1LL;
            // cout<<it<<" "<<lit<<" "<<mid<<" --> "<<who(it,mid)<<endl;
            ll got=who(it,mid);

            if (got && got <= lit)
            {
                ans = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }

        cout << ans << endl;
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