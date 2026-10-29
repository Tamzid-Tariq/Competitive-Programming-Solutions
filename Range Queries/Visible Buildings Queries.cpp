/*
Problem: Visible Buildings Queries
Link: https://cses.fi/problemset/task/3304/
Author: Tamzid Tariq
Date: 2025-11-25
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
    ll num, queries;
    cin >> num >> queries;

    vector<ll> vec(num);
    for (auto &ot : vec)
        cin >> ot;

    vector<vector<ll>> nxt(num + 2, vector<ll>(20, num + 1));

    stack<ll> st;

    for (ll j = num; j >= 1; j--)
    {
        while (!st.empty() && vec[st.top() - 1] <= vec[j - 1])
        {
            st.pop();
        }

        if (!st.empty())
            nxt[j][0] = st.top();

        st.push(j);
    }

    for (ll j = 1; j < 20; j++)
    {
        for (ll i = 1; i <= num; i++)
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
    }

    function<ll(ll, ll)> after = [&](ll now, ll step)
    {
        ll ret = now;
        for (ll j = 19; j >= 0; j--)
            if (step & (1LL << j))
                ret = nxt[ret][j];

        return ret;
    };

    for (ll i = 0; i < queries; i++)
    {
        ll start, end;
        cin >> start >> end;

        ll ans = 1, lo = 0, hi = end - start + 1;

        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;

            if (after(start, mid) <= end)
            {
                ans = mid + 1;
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
