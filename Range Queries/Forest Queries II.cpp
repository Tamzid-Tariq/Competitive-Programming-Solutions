/*
Problem: Forest Queries II
Link: https://cses.fi/problemset/task/1739/
Author: Tamzid Tariq
Date: 2025-12-24
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
 
struct SegTree2D
{
    ll siz;
    vector<vector<ll>> tree;
 
    void initialize(ll _n)
    {
        siz = 1;
        while (siz < _n)
            siz *= 2;
 
        tree.assign(2 * siz, vector<ll>(2 * siz, 0));
    }
 
 
    void update_x(ll y_node, ll x_node, ll start, ll end, ll x, ll val)
    {
        if (start == end)
        {
            tree[y_node][x_node] += val;
            return;
        }
 
        ll mid = (start + end) / 2;
        
        if (x <= mid)
            update_x(y_node, 2 * x_node + 1, start, mid, x, val);
        else
            update_x(y_node, 2 * x_node + 2, mid + 1, end, x, val);
 
        tree[y_node][x_node] = tree[y_node][2 * x_node + 1] + tree[y_node][2 * x_node + 2];
    }
 
    ll get_x(ll y_node, ll x_node, ll start, ll end, ll x1, ll x2)
    {
        if (end < x1 || start > x2)
            return 0;
 
        if (start >= x1 && end <= x2)
            return tree[y_node][x_node];
 
        ll mid = (start + end) / 2;
        return get_x(y_node, 2 * x_node + 1, start, mid, x1, x2) +
               get_x(y_node, 2 * x_node + 2, mid + 1, end, x1, x2);
    }
 
 
    void update_y(ll node, ll start, ll end, ll y, ll x, ll val)
    {
        update_x(node, 0, 0, siz - 1, x, val);
 
        if (start == end)
            return;
 
        ll mid = (start + end) / 2;
        
        if (y <= mid)
            update_y(2 * node + 1, start, mid, y, x, val);
        else
            update_y(2 * node + 2, mid + 1, end, y, x, val);
    }
 
    ll get_y(ll node, ll start, ll end, ll y1, ll y2, ll x1, ll x2)
    {
        if (end < y1 || start > y2)
            return 0;
 
        if (start >= y1 && end <= y2)
            return get_x(node, 0, 0, siz - 1, x1, x2);
 
        ll mid = (start + end) / 2;
        return get_y(2 * node + 1, start, mid, y1, y2, x1, x2) +
               get_y(2 * node + 2, mid + 1, end, y1, y2, x1, x2);
    }
 
    void update(ll y, ll x, ll val)
    {
        update_y(0, 0, siz - 1, y, x, val);
    }
 
    ll query(ll y1, ll x1, ll y2, ll x2)
    {
        return get_y(0, 0, siz - 1, y1, y2, x1, x2);
    }
};
 
 
void solve()
{
    ll num,queries;
    cin>>num>>queries;
 
    SegTree2D ST;
    ST.initialize(num);
 
    vector<vector<char>>grid(num,vector<char>(num));
 
    for(ll i=0;i<num;i++)
    {
        for(ll j=0;j<num;j++)
        {
            cin>>grid[i][j];
            
            if(grid[i][j]=='*')ST.update(i,j,1);
        }
    }
 
    for(ll i=0;i<queries;i++)
    {
        ll type;
        cin>>type;
 
        if(type==1)
        {
            ll x, y;
            cin>>x>>y;
        
 
            if(grid[x-1][y-1]=='*')
            {
                grid[x-1][y-1]='.';
                ST.update(x-1,y-1,-1);
            }
            else 
            {
                grid[x-1][y-1]='*';
                ST.update(x-1,y-1,1);
            }
        }   
        else 
        {
            ll x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
 
            cout<<ST.query(x1-1,y1-1,x2-1,y2-1)<<endl;
        }
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