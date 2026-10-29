/*
Problem: Knight's Tour
Link: https://cses.fi/problemset/task/1689/
Author: Tamzid Tariq
Date: 2025-12-05
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
    ll col, row;
    cin >> col >> row;

    col--, row--;
    vector<vector<ll>> ans(8, vector<ll>(8));

    ans[row][col] = 1;

    function<bool(ll, ll)> isvalid = [&](ll x, ll y)
    {
        return max(x, y) < 8 && min(x, y) >= 0 && !ans[x][y];
    };

    int posx[]={+2,+2,-2,-2,+1,+1,-1,-1};
    int posy[]={+1,-1,+1,-1,+2,-2,+2,-2};

    function<ll(ll, ll)>times=[&](ll x, ll y)
    {
        ll ret = 0;

        for (ll i = 0; i < 8; i++)
        {
            ll newx = x + posx[i], newy = y + posy[i];
            if (isvalid(newx, newy))
            {
                ret++;
            }
        }
        return ret;
    };

    function<bool(ll, ll)> go = [&](ll x, ll y)
    {
        if (ans[x][y] == 64)
            return true;

        multiset<tuple<ll, ll, ll>> ms;

        for (ll i = 0; i < 8; i++)
        {
            ll newx = x + posx[i], newy = y + posy[i];
            if (isvalid(newx, newy))
            {
                ms.insert({times(newx, newy), newx, newy});
            }
        }

        bool ret = false;

        for (auto [trash, it, lit] : ms)
        {
            ans[it][lit] = ans[x][y] + 1;
            if (go(it, lit))
                return true;
            ans[it][lit] = 0;
        }
        return false;
    };

    go(row, col);

    for (ll i = 0; i < 8; i++)
    {
        for (ll j = 0; j < 8; j++)
        {
            cout << ans[i][j] << " ";
        }
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