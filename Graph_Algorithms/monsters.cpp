/*
Problem: Monsters
Link: https://cses.fi/problemset/task/1194/
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
const ll INF = LLONG_MAX;
 
 
ll col, row;
vector<pair<ll, ll>> mindex;
char graph[1005][1005];
ll disx[] = {1, -1, 0, 0};
ll disy[] = {0, 0, -1, 1};
string way = "DULR";
ll vis[1005][1005];
map<pair<ll, ll>, pair<ll, ll>> parent;

char pos[1005][1005];
ll dism[1005][1005];
ll dist[1005][1005];
 
bool isValid(ll x, ll y)
{
	if (x < 0 || y < 0 || x >= col || y >= row)
		return false;
	if (graph[x][y] == '#' || vis[x][y] == 1)
		return false;
	return true;
}
void bfsm()
{
	
	memset(vis,0,sizeof(vis));
 
	queue<pair<ll, ll>> q;
	for (auto it : mindex)   
	{
		ll x = it.first;
		ll y = it.second;
		vis[x][y] = 1;
		q.push({x, y});
		dism[x][y] = 1;
	}
 
	while (!q.empty())
	{
		pair<ll, ll> p = q.front();
		q.pop();
		ll currx = p.first;
		ll curry = p.second;
		for (int i = 0; i < 4; i++)
		{
			ll newx = currx + disx[i];
			ll newy = curry + disy[i];
			if (isValid(newx, newy))
			{
				q.push({newx, newy});
				vis[newx] [newy] = 1;
				(dism[newx][newy] == 0) ? (dism[newx] [newy] = dism[currx] [curry] + 1) : (dism[newx] [newy] = min(dism[newx] [newy], dism[currx] [curry] + 1));
			}
		}
	}
}
 
void bfs(ll x, ll y)
{
	memset(vis,0,sizeof(vis));
	
	vis[x][y] = 1;
	queue<pair<ll, ll>> q;
	q.push({x, y});
	dist[x][y] = 1;
	parent[{x, y}] = {-1, -1};
	pos[x][y] = 1;
	while (!q.empty())
	{
		pair<ll, ll> p = q.front();
		q.pop();
		ll currx = p.first;
		ll curry = p.second;
		for (int i = 0; i < 4; i++)
		{
			ll newx = currx + disx[i];
			ll newy = curry + disy[i];
			if (isValid(newx, newy))
			{
				q.push({newx, newy});
				vis[newx] [newy] = 1;
				dist[newx][newy] = dist[currx] [curry] + 1;
				parent[{newx, newy}] = {currx, curry};
				pos[newx][newy] = way[i];
			}
		}
	}
}
 
void solve()
{
 
	vector<pair<ll, ll>> aindex;
	cin >> col >> row;
	for (ll i = 0; i < col; i++)
	{
		for (ll j = 0; j < row; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 'M')
				mindex.push_back({i, j});
			if (graph[i][j] == 'A')
				aindex.push_back({i, j});
		}
	}
 
	
	bfsm();
    
	for (auto it : aindex)
		bfs(it.first, it.second);
 
	for (ll i = 0; i < col; i += col - 1)
	{
		for (ll j = 0; j < row; j++)
		{
			// cout<<dist[{i, j}]<< " "<<dism[{i, j}]<<endl;
			if ((dist[i][j] < dism[i][j]) || (dist[i] [j] != 0 && dism[i] [j] == 0))
			{
				vector<char> path;
				path.push_back(pos[i][j]);
				for (pair<ll, ll> k = parent[{i, j}];; k = parent[k])
				{
					if (k.first == -1)
						break;
					path.push_back(pos[k.first][k.second]);
				}
				cout << "YES\n";
				cout << path.size() - 1 << endl;
				for (ll i = path.size() - 2; i >= 0; i--)
					cout << path[i];
				return;
			}
		}
	}
	for (ll i = 1; i < col - 1; i++)
	{
		if ((dist[i] [0] < dism[i] [0]) || (dist[i] [0] != 0 && dism[i] [0] == 0))
		{
			vector<char> path;
			path.push_back(pos[i][0]);
			for (pair<ll, ll> k = parent[{i, 0}];; k = parent[k])
			{
				if (k.first == -1)
					break;
				path.push_back(pos[k.first][k.second]);
			}
			cout << "YES\n";
			cout << path.size() - 1 << endl;
			for (ll i = path.size() - 2; i >= 0; i--)
				cout << path[i];
			return;
		}
		if ((dist[i][row - 1] < dism[i][row - 1]) || (dist[i][row - 1] != 0 && dism[i] [row - 1] == 0))
		{
			vector<char> path;
			path.push_back(pos[i][row - 1]);
			for (pair<ll, ll> k = parent[{i, row - 1}];; k = parent[k])
			{
				if (k.first == -1)
					break;
				path.push_back(pos[k.first][k.second]);
			}
			cout << "YES\n";
			cout << path.size() - 1 << endl;
			for (ll i = path.size() - 2; i >= 0; i--)
				cout << path[i];
			return;
		}
	}
	cout << "NO\n";
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