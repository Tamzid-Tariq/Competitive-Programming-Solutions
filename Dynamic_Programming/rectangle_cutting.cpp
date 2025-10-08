/*
Problem: Rectangle Cutting
Link: https://cses.fi/problemset/task/1744/
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

ll findans(ll h, ll w)
{
	if (h == w)
		return 0;
	ll ans = INT_MAX;

	for (ll i = 1; i < h; i++)
	{
		// for(ll j=1;j<=w/2;j++)
		// {
		ans = 1 + findans(h - i, w) + findans(i, w);
		// ans=min(ans,1+findans(h,w-j)+findans(h,j));
		//}
	}
	return ans;
}

void solve()
{
	ll height, width;
	cin >> height >> width;

	ll ans[height + 2][width + 2];

	memset(ans, 0LL, sizeof ans);
	ll result = LLONG_MAX;

	for (ll i = 1; i <= height; i++)
	{
		for (ll j = 1; j <= width; j++)
		{
			if (i == j)
			{
				ans[i][j] = 0;
				continue;
			}

			ll result = LLONG_MAX;
			for (ll h = 1; h <= i / 2; h++)
				result = min(result, 1 + ans[h][j] + ans[i - h][j]);

			for (ll w = 1; w <= j / 2; w++)
				result = min(result, 1 + ans[i][w] + ans[i][j - w]);
			ans[i][j] = result;
		}
	}
	cout << ans[height][width] << endl;
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