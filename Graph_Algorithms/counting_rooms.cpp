/*
Problem: Counting Rooms
Link: https://cses.fi/problemset/task/1192/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int;

using namespace std;
char graph[1001][1001];
bool vis[1001][1001]={false};
int col,row;

bool isValid(int x, int y){
    if(x<0 || y<0 || x>=col || y>=row) return false;
if(graph[x][y] == '#' && vis[x][y]==true)return false;
if(graph[x][y] == '.' && vis[x][y]==false)return true;
return false;
}

void dfs(int x, int y){
    vis[x][y]=true;

    if(isValid(x,y+1)) dfs(x,y+1);
    if(isValid(x,y-1)) dfs(x,y-1);
    if(isValid(x+1,y)) dfs(x+1,y);
    if(isValid(x-1,y)) dfs(x-1,y);

}

void solve()
{
    
    cin >> col >> row;
    for(ll i=0;i<col;i++)
    for(ll j=0;j<row;j++)
    cin>>graph[i][j];
    ll count=0;
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++)
        if(graph[i][j]=='.' && vis[i][j]==false){
            count++;
            dfs(i,j);
        }
    }cout<<count<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    n = 1;
    //cin >> n;
    for (ll i = 1; i <= n; ++i)
    {
        solve();
    }
    return 0;
}