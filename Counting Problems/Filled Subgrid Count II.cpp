/*
Problem: Filled Subgrid Count II
Link: https://cses.fi/problemset/task/3414/
Author: Tamzid Tariq
Date: 2026-06-23
Status: Accepted ✓
*/

#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
#define endl '\n'
const ll modular = 1e9 + 7;
const double pi = acos(-1.0);
const ll INF = 1e18;

void solve()
{
   ll row,k;
   cin>>row>>k;

   ll col = row;

   vector<vector<char>>grid(row+1,vector<char>(col+1));
   for(ll i=1;i<=row;i++)
   {
        for(ll j=1;j<=col;j++)
        {
            cin>>grid[i][j];
        }
   }

   vector<vector<ll>>up(row+1,vector<ll>(col+1)),result(row+1,vector<ll>(col+1));
   vector<ll>ans(k);

   stack<ll>st;
   for(ll i=1;i<=row;i++)
   {
        while(!st.empty())st.pop();
        st.push(0);
        for(ll j=1;j<=col;j++)
        {
            up[i][j] = 1 + (grid[i-1][j]==grid[i][j]?up[i-1][j]:0LL);

            while(st.top()!=0 && up[i][st.top()]>=up[i][j] && grid[i][st.top()] == grid[i][j])st.pop();

            result[i][j] = (grid[i][st.top()]==grid[i][j]?result[i][st.top()]:0) + up[i][j] * (j - st.top());
            ans[grid[i][j]-'A'] += result[i][j];

            st.push(j);
        }
   }

   for(auto it:ans)cout<<it<<endl;
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