/*
Problem: Intersection Points
Link: https://cses.fi/problemset/task/1740/
Author: Tamzid Tariq
Date: 2026-03-16
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
 
struct segtree
{
	ll siz = 1;
	vector<ll> val;
 
	void initialize(ll num)
	{
		while (siz < num)
			siz *= 2;
		val.assign(2 * siz + 1, 0);
	}
 
	ll merge(ll val1, ll val2)
	{
		return (val1 + val2);
	}
 
	void build(vector<ll> &vec, ll parent, ll start, ll end)
	{
		if (end - start == 1)
		{
			if (start < vec.size())
				val[parent] = vec[start];
			return;
		}
 
		ll mid = (start + end) / 2;
 
		build(vec, 2 * parent + 1, start, mid);
		build(vec, 2 * parent + 2, mid, end);
 
		val[parent] = merge(val[2 * parent + 1], val[2 * parent + 2]);
	}
 
	void build(vector<ll> &vec)
	{
		build(vec, 0, 0, siz);
	}
 
	void update(ll value, ll ind, ll parent, ll start, ll end)
	{
		if (end - start == 1)
		{
			val[parent] = value;
			return;
		}
 
		ll mid = (start + end) / 2;
 
		if (ind < mid)
			update(value, ind, 2 * parent + 1, start, mid);
		else
			update(value, ind, 2 * parent + 2, mid, end);
 
		val[parent] = merge(val[2 * parent + 1], val[2 * parent + 2]);
	}
 
	void update(ll val, ll ind)
	{
		update(val, ind, 0, 0, siz);
	}
 
	ll query(ll lo, ll hi, ll parent, ll start, ll end)
	{
		if (lo <= start && end - 1 <= hi)
			return val[parent];
 
		if (start > hi || end <= lo)
			return 0;
 
		ll mid = (start + end) / 2;
 
		return merge(query(lo, hi, 2 * parent + 1, start, mid), query(lo, hi, 2 * parent + 2, mid, end));
	}
 
	ll query(ll lo, ll hi)
	{
		return query(lo, hi, 0, 0, siz);
	}
};
 
void solve()
{
	ll num;
	cin >> num;
 
	vector<tuple<ll, ll, ll, ll>> vec;
 
	ll mini = 0, maxi = 0;
	for (ll i = 0; i < num; i++)
	{
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
 
		mini = min({mini, y1, y2});
		maxi = max({maxi, y1, y2});
		if (x1 == x2)
		{
			vec.push_back({x1, 0, y1, y2});
		}
		else if (y1 == y2)
		{
			vec.push_back({x1, 1, y1, 0});
			vec.push_back({x2, -1, y2, 0});
		}
	}
 
	sort(vec.begin(), vec.end());
	ll offset = abs(mini), span = maxi + abs(mini) + 5, ans = 0LL;
 
	segtree ST;
	ST.initialize(span);
	vector<ll> times(span);
 
	for (auto [x, type, y1, y2] : vec)
	{
		y1 += offset;
		y2 += offset;
 
		if (!type)
		{
			ans += ST.query(y1, y2);
		}
		else if (type == 1)
		{
			times[y1]++;
			ST.update(times[y1], y1);
		}
		else
		{
			times[y1]--;
			ST.update(times[y1], y1);
		}
	}
 
	cout << ans << endl;
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