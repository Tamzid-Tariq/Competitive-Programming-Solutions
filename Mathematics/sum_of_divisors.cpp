/*
Problem: Sum of Divisors
Link: https://cses.fi/problemset/task/1082/
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

ll modularBinaryExponentiation(ll base, ll exponent){
    if(exponent==0) return 1;
    ll result=modularBinaryExponentiation(base,exponent/2);
    if(exponent & 1)return (((((result*result))%modular)*base)%modular);
    else return ((result*result)%modular);
}

void solve()
{
    ll num;
    cin >> num;
    ll ans = 0;

    // 1->1, 2->1,2 ; 3-> 1, 3 ; 4-> 1,2,4; 5-> 1,5; 6->1,2,3,6
    ll last = 0;
    for (ll i = 1; i <= num;)
    {
        ll times = num / i;

        last = i - 1;
        i = (num / times) + 1;
        ll val =(( ((i%modular) * ((i - 1)%modular) % modular)) *modularBinaryExponentiation(2,modular-2))%modular;
        if (val < 0)
           val += modular;
        ll minus = (( ((last%modular) * ((last+1)%modular)) % modular) *modularBinaryExponentiation(2,modular-2))%modular;
        if (minus < 0)
           minus += modular;
        val -= minus;
        if(val<0)val+=modular;
        times%=modular;
        if(times<0)times+=modular;
        ll plus=(val * (times))%modular;
        if(plus<0)plus+=modular;
        ans += plus;
        ans%=modular;
        if(ans<0)ans+=modular;
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