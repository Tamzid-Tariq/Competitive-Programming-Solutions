/*
Problem: Third Permutation
Link: https://cses.fi/problemset/task/3422/
Author: Tamzid Tariq
Date: 2026-02-14
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

    vector<ll> vec(num), vecb(num);
    for (auto &it : vec)
        cin >> it;

    for (auto &it : vecb)
        cin >> it;

    vector<ll> times(num + 1), ans(num);
    queue<ll> avail;

    for (ll i = 0; i < num; i++)
    {
        if (avail.size())
        {
            ans[i] = avail.front();
            avail.pop();
        }
        times[vec[i]]++;
        if (times[vec[i]] == 2)
            avail.push(vec[i]);

        times[vecb[i]]++;
        if (times[vecb[i]] == 2)
            avail.push(vecb[i]);
    }

    for (ll i = 0; i < num; i++)
    {
        if (!ans[i])
        {
            ll times=avail.size();
            bool got=0;

            for(ll j=0;j<times;j++)
            {
                ll now = avail.front();
                avail.pop();
                if (now != vec[i] && now != vecb[i])
                {
                    got=1;
                    ans[i] = now;
                    break;
                }
                else
                    avail.push(now);
            }

            if(!got)
            {
                cout<<"IMPOSSIBLE\n";
                return;
            }
        }
    }
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
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