/*
Problem: Rectangle Cutting
Link: https://cses.fi/problemset/task/1744/
Author: Tamzid Tariq
Date: 2024-01-01
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

ll ans[503][503];

void solve()
{
    ll row,col;
    cin>>row>>col;

    memset(ans,-1,sizeof(ans));

    function<ll(ll,ll)>go=[&](ll x,ll y)
    {
        if(x==y) return 0LL;

        if(ans[x][y]!=-1)return ans[x][y];

        ll ret=INF;

        for(ll i=1;2*i<=x;i++)ret = min(ret, 1LL + go(i,y) + go(x-i,y));

        for(ll j=1;2*j<=y;j++) ret = min(ret,1LL + go(x,j) + go(x,y-j));

        return ans[x][y] = ans[y][x] = ret;
    };

    cout<<go(row,col)<<endl;
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