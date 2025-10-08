/*
Problem: Exponentiation
Link: https://cses.fi/problemset/task/1095/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ll = long long int;
using ull = unsigned long long int;
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll mod = 1e9 + 7;

ll exponentiation(ll base,ll power){
    if(power==0)return 1;
    ll result=exponentiation(base,power/2);
    result=((result%mod)*(result%mod))%mod;
    if(power&1)result=((result*base)%mod);
    return result;
}

void solve()
{
    ll a,b;
    cin>>a>>b;

    cout<<exponentiation(a,b)<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    n = 1;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}