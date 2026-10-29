/*
Problem: Counting Towers
Link: https://cses.fi/problemset/task/2413/
Author: Tamzid Tariq
Date: 2025-12-09
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

ll ans[1000006][3];

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



ll go(ll pos, ll state)
{
    
    if (pos == 1)
    {
        return 1;
    }

    if (ans[pos][state] != -1)
        return ans[pos][state];

    ll ret = 0;
    
    if(state)
    {
        ret = add(go(pos-1,0),multiply(2,go(pos-1,1)));
    }

    else 
    {
        ret= add(go(pos-1,1),multiply(4,go(pos-1,0)));
    }
    return ans[pos][state] = ret;
}

void solve()
{
    ll num;
    cin >> num;

    cout << add(go(num, 0),go(num,1)) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(ans, -1, sizeof(ans));

    ll n;
    n = 1;
    cin >> n;
    for (ll i = 1; i <= n; ++i)
    {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}