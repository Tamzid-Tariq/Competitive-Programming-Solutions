/*
Problem: Creating Strings II
Link: https://cses.fi/problemset/task/1715/
Author: Tamzid Tariq
Date: 2025-10-09
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

ll factorial[1000006];
 
void precompute()
{
    factorial[0] = factorial[1] = 1;
 
    for (ll i = 2; i <= 1000000; i++)
        factorial[i] = (factorial[i - 1] * i) % modular;
}
 
ll modularBinaryExponentiation(ll base, ll exponent)
{
    if (exponent == 0)
        return 1;

    ll result = modularBinaryExponentiation(base, exponent / 2);
    result %= modular;

    if (exponent & 1)
        return (((((result * result)) % modular) * base) % modular);
    else
        return ((result * result) % modular);
}

ll multiply(ll val1, ll val2)
{
    ll result = (val1 % modular) * (val2 % modular);
    return result % modular;
}

ll divide(ll val1, ll val2)
{
    ll denominator = modularBinaryExponentiation(val2 % modular, modular - 2) % modular;
    ll result = multiply(val1, denominator);

    return result % modular;
}


void solve()
{
    string s;
    cin>>s;

    ll num = s.size();

    ll ans=factorial[num];

    ll denom=1LL;

    vector<ll>times(26);
    for(auto it:s)times[it-'a']++;

    for(ll i=0;i<26;i++)
    {
        if(times[i])
        {
            denom = multiply(denom,factorial[times[i]]);
        }
    }

    ans=divide(ans,denom);
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    precompute();

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