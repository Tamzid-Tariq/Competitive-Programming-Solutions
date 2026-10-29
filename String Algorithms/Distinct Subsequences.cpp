/*
Problem: Distinct Subsequences
Link: https://cses.fi/problemset/task/1149/
Author: Tamzid Tariq
Date: 2025-11-04
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

ll add(ll val1, ll val2)
{
    ll result = (val1 % modular) + (val2 % modular);
    return result % modular;
}

ll subtract(ll val1, ll val2)
{
    ll result = modular + ((val1 % modular) - (val2 % modular));
    return result % modular;
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
    cin >> s;

    ll num = s.size();
    ll ans[num + 1][26];

    for (ll i = 0; i <= num; i++)
    {
        for (ll j = 0; j < 26; j++)
            ans[i][j] = 0;
    }

    for (ll i = 1; i <= num; i++)
    {
        ans[i][s[i - 1] - 'a'] = add(ans[i - 1][s[i - 1] - 'a'], 1LL);

        for (ll j = 0; j < 26; j++)
        {
            if (j == s[i - 1] - 'a')
                continue;
            ans[i][s[i - 1] - 'a'] = add(ans[i][s[i - 1] - 'a'], ans[i - 1][j]);
            ans[i][j] = ans[i - 1][j];
        }
    }

    ll result = 0;
    for (ll i = 0; i < 26; i++)
    {
        result = add(result, ans[num][i]);
    }

    cout << result << endl;
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