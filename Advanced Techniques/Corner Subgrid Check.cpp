/*
Problem: Corner Subgrid Check
Link: https://cses.fi/problemset/task/3360/
Author: Tamzid Tariq
Date: 2026-08-23
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

const ll N = 3005;
ll got[N][N];

void solve()
{
    ll num, times;
    cin >> num >> times;

    vector<string> vec(num);
    for (auto &ot : vec)
        cin >> ot;

    vector<vector<ll>>where(times);

    vector<ll>ans(times);
    for (ll i = 0; i < num; i++)
    {
        for (ll j = 0; j < num; j++)
        {
            where[vec[i][j]-'A'].push_back(j);
        }

        for(ll j=0;j<times;j++)
        {
            if(ans[j] || where[j].size()<2)
            {
                where[j].clear();
                continue;
            }

            for(ll k = 0;k<where[j].size()-1 && !ans[j];k++)
            {
                for(ll l = k+1;l<where[j].size() && !ans[j];l++)
                {
                    ll x = where[j][k],y = where[j][l];

                    if(got[x][y]&(1LL<<j))
                    {
                        // cout<<(char)('A' + j)<<" -> "<<x+1<<" "<<y+1<<endl;
                        ans[j]=1;
                    }

                    got[x][y]|=(1LL<<j);
                }
            }
            where[j].clear();
        }
    }

    for(auto it:ans)cout<<(it?"YES\n":"NO\n");
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