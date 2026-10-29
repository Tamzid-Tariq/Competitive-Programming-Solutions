/*
Problem: Coding Company
Link: https://cses.fi/problemset/task/1665/
Author: Tamzid Tariq
Date: 2026-08-25
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

const ll offset = 5000;

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

ll fact[52];

void solve()
{
    ll num, k;
    cin >> num >> k;

    vector<ll> vec(num);
    for (auto &it : vec)
        cin >> it;

    sort(vec.begin(), vec.end());

    fact[0]=1;
    for(ll i=1;i<=51;i++)fact[i]=multiply(fact[i-1],i);
    
    vector<vector<ll>> ans(52, vector<ll>(2 * offset + 2));
    ans[0][offset] = 1;

    for (ll i = 0; i < num; i++)
    {
        vector<vector<ll>> temp(52, vector<ll>(2 * offset + 2,0));
        for (ll j = 0; j <= min(num/2, num - i); j++)
        {
            for (ll penalty = 0; penalty <= offset + k; penalty++)
            {
                if(!ans[j][penalty])continue;

                // create a group of its own -> consisting of himself alone
                temp[j][penalty] = add(temp[j][penalty], ans[j][penalty]);

                // joining any existing groups that has been formed already by others
                temp[j][penalty] = add(temp[j][penalty], multiply(j,ans[j][penalty]));

                if (j && penalty + vec[i]<=offset+k)
                {
                    temp[j - 1][penalty + vec[i]] = add(temp[j - 1][penalty + vec[i]], multiply(j, ans[j][penalty]));
                }

                if(penalty >= vec[i])
                    temp[j + 1][penalty - vec[i]] = add(temp[j + 1][penalty - vec[i]], ans[j][penalty]);
            }
        }
        swap(temp, ans);
    }

    ll result = 0;
    for (ll penalty = offset; penalty <= offset + k; penalty++)
        result = add(result, ans[0][penalty]);

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