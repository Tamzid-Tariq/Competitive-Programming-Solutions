/*
Problem: Grid Path Description
Link: https://cses.fi/problemset/task/1625/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

typedef int ll;
using namespace std;
#define endl '\n';

ll num = 7;
ll posx[] = {0, 0, +1, -1};
ll posy[] = {-1, +1, 0, 0};
string path = "LRDU";
bool visited[7][7];
string s;

bool isinside(ll x, ll y)
{
    return min(x, y) >= 0 && max(x, y) < num;
}

bool isEmpty(ll x, ll y)
{
    return isinside(x, y) && !visited[x][y];
}

void solve()
{
    cin >> s;

        ll ans = 0;
 
    function<void(ll, ll, ll)> go = [&](ll x, ll y, ll pos)
    {
        if (x == num - 1 && y == 0)
        {
            ans+=(pos==48);
            return;
        }
 
        if (isEmpty(x, y + 1) && isEmpty(x, y - 1) && !isEmpty(x - 1, y) && !isEmpty(x + 1, y))
            return;
 
        if (!isEmpty(x, y + 1) && !isEmpty(x, y - 1) && isEmpty(x - 1, y) && isEmpty(x + 1, y))
            return;
        
 
        // checkerboard
 
        if (isEmpty(x - 1, y) && isEmpty(x, y - 1) && !isEmpty(x - 1, y - 1))
            return;
 
        if (isEmpty(x - 1, y) && isEmpty(x, y + 1) && !isEmpty(x - 1, y + 1))
            return;
 
        if (isEmpty(x + 1, y) && isEmpty(x, y - 1) && !isEmpty(x + 1, y - 1))
            return;
 
        if (isEmpty(x + 1, y) && isEmpty(x, y + 1) && !isEmpty(x + 1, y + 1))
            return;
 
        for (ll i = 0; i < 4; i++)
        {
            if (s[pos] == '?' || s[pos] == path[i])
            {
                if (isEmpty(x + posx[i], y + posy[i]))
                {
                    visited[x + posx[i]][y + posy[i]] = true;
                    // ret +=
                    go(x + posx[i], y + posy[i], pos + 1);
                    visited[x + posx[i]][y + posy[i]] = false;
                }
            }
        }
    };

    visited[0][0] = true;
    go(0, 0, 0);
    cout << ans << endl;
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