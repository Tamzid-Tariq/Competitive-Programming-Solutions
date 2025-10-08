/*
Problem: Labyrinth
Link: https://cses.fi/problemset/task/1193/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int;
using ull = unsigned long long int;
using namespace std;
const ll modular = 1e9 + 7;
const double pi = 22 / 7;

ll col, row, startx, starty, endx, endy;
 
char graph[1005][1005];
ll dirx[] = {1, -1, 0, 0};
ll diry[] = {0, 0, 1, -1};
string dir = "DURL";

ll dist[1005][1005] = {0x0};
char position[1005][1005];
pair<int, int> parent[1005][1005];

//vector<vector<pair<int, int>>> parent;

bool isValid(ll x, ll y)
{
    if (x < 0 || y < 0 || x >= col || y >= row)
        return false;
    if (dist[x][y] != 0 || graph[x][y]=='#')
        return false;
    return true;
}

void bfs(ll x, ll y)
{
    queue<pair<ll, ll>> q;
    q.push({x, y});
    dist[x][y] = 1;
    parent[x][y]={-1,-1};

    while (!q.empty())
    {
        pair<ll, ll> p = q.front();
        q.pop();
        ll currx = p.first;
        ll curry = p.second;
        if(currx==endx && curry==endy){
            cout<<"YES\n";
            vector<char>ans;
            ans.push_back({position[endx][endy]});
            while(1){
                ll pastx,pasty;
                pastx=parent[currx][curry].first;
                pasty=parent[currx][curry].second;
                if(pastx==startx && pasty==starty)break;
                ans.push_back(position[pastx][pasty]);
                currx=pastx;
                curry=pasty;
            }cout<<ans.size()<<endl;
            for(ll i=ans.size()-1;i>=0;i--)cout<<ans[i];
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            ll newx = currx + dirx[i];
            ll newy = curry + diry[i];
            if (isValid(newx, newy))
            {
                q.push({newx, newy});
                dist[newx][newy] = dist[currx][curry] + 1;
                parent[newx][newy]={currx,curry};
                position[newx][newy]=dir[i];
            }
        }
    }cout<<"NO\n";
    return;
}

void solve()
{

    cin >> col >> row;

    

    for (ll i = 0; i < col; i++)
    {
        for (ll j = 0; j < row; j++)
        {
            cin >> graph[i][j];
            
            if (graph[i][j] == 'A')
                startx = i, starty = j;
            if (graph[i][j] == 'B')
                endx = i, endy = j;
            
        }
    }
    
    bfs(startx, starty);
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