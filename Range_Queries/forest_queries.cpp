/*
Problem: Forest Queries
Link: https://cses.fi/problemset/task/1652/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
const ll modular = 1e9 + 7;
const double pi = acos(-1.0);
const ll INF = 10000000000LL;



void solve()
{
    ll row,col,query;
    cin>>row>>query;
    col=row;

    ll grid[row+1][col+1];

    for(ll i=1;i<=row;i++)
    {
        for(ll j=1;j<=col;j++)
        {
            char c; cin>>c; 
            grid[i][j]=(c=='*');
        }
    }

    ll ans[row+1][col+1];
    memset(ans,0LL,sizeof ans);

    for(ll i=1;i<=row;i++)
    {
        for(ll j=1;j<=col;j++)
        {
            ans[i][j]=grid[i][j];
            ans[i][j]+=ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1];
        }
    }

    while(query--)
    {
        ll startx,starty,endx,endy;
        cin>>startx>>starty>>endx>>endy;

        cout<<ans[endx][endy]-ans[startx-1][endy]-ans[endx][starty-1]+ans[startx-1][starty-1]<<endl;
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