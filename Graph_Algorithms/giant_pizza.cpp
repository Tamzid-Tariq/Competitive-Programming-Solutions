/*
Problem: Giant Pizza
Link: https://cses.fi/problemset/task/1684/
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
 
ll num, edges;
vector<vector<ll>> adj, reverseadj;
vector<ll>visited,visitorder,ans;
vector<vector<ll>>allscc;
 
void dfs(ll node)
{
	visited[node]=1;
	for(auto it:adj[node])
	{
		if(!visited[it])dfs(it);
	}
	visitorder.push_back(node);
}
 
void dfs2(ll node,ll times)
{
	visited[node]=1;
	ans[node]=times;
	allscc[times-1].push_back(node);
 
	for(auto it:reverseadj[node])
	{
		if(!visited[it])
		dfs2(it,times);
	}
}
 
void kosaraju()
{
	for(ll i=0;i<num;i++)
	{
		if(!visited[i])dfs(i);
	}
 
	reverse(visitorder.begin(),visitorder.end());
	visited.assign(num,0);
 
	ll scc=0;
	for(auto i:visitorder)
	{
		if(!visited[i])
		{
			dfs2(i,++scc);
		}
	}

	vector<ll>result(num/2);

	for(ll i=0;i<num;i+=2)
	{
		if(ans[i]==ans[i+1])
		{
			cout<<"IMPOSSIBLE\n";
			return;
		}
		result[i/2]=(ans[i]>ans[i+1]);
	}
 
	
	
	for(auto it:result)cout<<((it)?"+ ":"- ");
	cout<<endl;
	
}
 
 
void solve()
{
	ll n,m;
	cin>>n>>m;
 
	num=2*m;
	
	adj.resize(num),reverseadj.resize(num),visited.resize(num),visitorder.resize(num),ans.resize(num),allscc.resize(num);
	
	for(ll i=0;i<n;i++)
	{
		char sign1,sign2;
		ll val1,val2;
 
		cin>>sign1>>val1>>sign2>>val2;
 
		val1--,val2--;
 
		adj[val1*2+(sign1=='+')].push_back(val2*2+(sign2=='-'));
		adj[val2*2+(sign2=='+')].push_back(val1*2+(sign1=='-'));
 
		reverseadj[val2*2+(sign2=='-')].push_back(val1*2+(sign1=='+'));
		reverseadj[val1*2+(sign1=='-')].push_back(val2*2+(sign2=='+'));
	}
 
	kosaraju();
 
	
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