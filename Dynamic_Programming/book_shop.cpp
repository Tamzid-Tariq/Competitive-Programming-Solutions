/*
Problem: Book Shop
Link: https://cses.fi/problemset/task/1158/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

typedef int ll;
typedef unsigned long long int ull;
using namespace std;
const ll modular = 1e9 + 7;
const double pi = acos(-1.0);


//ll dp[1009][100009];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll num, capacity;
	cin >> num >> capacity;
	ll value[num + 1], weight[num + 1];
	for (ll i = 0; i < num; i++)
	{
		cin >> weight[i];
	}
	for (ll i = 0; i < num; i++)
	{
		cin >> value[i];
	}
	ll dp[num+1][capacity+1];
	for (ll i = 0; i <= num; i++)
	{
		for (ll j = 0; j <= capacity; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (j - weight[i - 1] >= 0)
			{
				dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[num][capacity] << endl;
	return 0;
}