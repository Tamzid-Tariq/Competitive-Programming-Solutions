/*
Problem: Christmas Party
Link: https://cses.fi/problemset/task/1717/
Author: Tamzid Tariq
Date: 2026-02-15
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

const ll N = 1000000;
ll d[N+2];

ll add(ll val1, ll val2)
{
    ll result = (val1 % modular) + (val2 % modular);
    return result % modular;
}


ll multiply(ll val1, ll val2)
{
    ll result = (val1 % modular) * (val2 % modular);
    return result % modular;
}

void derangement()
{
    d[2]=1;

    for(int i=3;i<=N;i++)d[i]=multiply(i-1,add(d[i-1],d[i-2]));
}

void solve()
{
    ll num;
    cin>>num;

    cout<<d[num]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    derangement();

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