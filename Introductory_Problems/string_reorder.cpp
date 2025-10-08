/*
Problem: String Reorder
Link: https://cses.fi/problemset/task/1743/
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
    string s;
    cin >> s;

    vector<ll> times(26);

    ll num = s.size();

    for (ll i = 0; i < num; i++)
        times[s[i] - 'A']++;

    string ans;
    // for(ll j=0;j<26;j++)cout<<times[j]<<" ";
    // cout<<endl;
    for (ll i = 0; i < s.size(); i++)
    {
        bool done = 0;
        char now;
        for (ll j = 0; j < 26; j++)
        {
            if (!times[j])
                continue;

            if (i + 2 * times[j] - 1 > num)
            {
                done = 0;
                break;
            }

            if (!done && (!i || (ans.back() - 'A') != j))
            {
                now = (char)('A' + j);
                done = 1;
            }
            else if (done && (ans.back() - 'A') != j && i + 2 * times[j] - 1 == num)
            {
                now = (char)('A' + j);
                done = 1;
            }
        }
        if (!done)
        {
            cout << -1 << endl;
            return;
        }
        else
        {
            ans += now;
            times[now - 'A']--;
        }
    }
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