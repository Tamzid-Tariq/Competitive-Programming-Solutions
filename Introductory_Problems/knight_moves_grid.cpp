/*
Problem: Knight Moves Grid
Link: https://cses.fi/problemset/task/3217/
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
    ll num;
    cin >> num;

    vector<vector<bool>> visited(num, vector<bool>(num));
    vector<vector<ll>> ans(num, vector<ll>(num));

    visited[0][0] = 1;

    vector<ll> posx = {+1, -1, +1, -1, +2, -2, +2, -2};
    vector<ll> posy = {+2, +2, -2, -2, +1, +1, -1, -1};

    function<bool(ll, ll)> isvalid = [&](ll x, ll y)
    {
        return min(x, y) >= 0 && max(x, y) < num && !visited[x][y];
    };

    queue<pair<ll, ll>> q;
    q.push({0, 0});

    while (!q.empty())
    {
        auto &[x, y] = q.front();
        q.pop();

        for (ll i = 0; i < 8; i++)
        {
            ll newx = posx[i] + x, newy = posy[i] + y;

            if (isvalid(newx, newy))
            {
                ans[newx][newy] = ans[x][y] + 1;
                visited[newx][newy] = 1;
                q.push({newx, newy});
            }
        }
    }

    for (ll i = 0; i < num; i++)
    {
        for (ll j = 0; j < num; j++)
            cout << ans[i][j] << " ";
        cout << endl;
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