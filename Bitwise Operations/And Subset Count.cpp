/*
Problem: And Subset Count
Link: https://cses.fi/problemset/task/3141/
Author: Tamzid Tariq
Date: 2026-03-10
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

const ll N = 2e5;

ll pw[N+5];

ll multiply(ll val1,ll val2)
{
    val1%=modular;
    val2%=modular;

    return ((val1* val2)%modular);
}
void precompute()
{
    pw[0]=1;
    for(ll i=1;i<=N;i++)pw[i] = multiply(pw[i-1],2);
}

ll subtract(ll val1,ll val2)
{
    val1+=modular; val1%=modular;
    val2+=modular; val2%=modular;

    return ((val1-val2)%modular + modular)%modular;
}

void solve()
{
    ll num;
    cin>>num;
    
    vector<ll>vec(num);
    vector<ll>times(num+1);

    for(auto &it:vec)
    {
        cin>>it;
        times[it]++;
    }

    for(ll bit=0;bit<=19;bit++)
    {
        for(ll i=0;i<=num;i++)
        {
            if(!(i&(1LL<<bit)) && (i^(1LL<<bit))<=num) times[i] += times[i ^ (1LL<<bit)];
        }
    }

    for(ll i=0;i<=num;i++)times[i] = subtract(pw[times[i]],1);

    for(ll bit=0;bit<=19;bit++)
    {
        for(ll i=0;i<=num;i++)
        {
            if(!(i&(1LL<<bit)) && (i^(1LL<<bit))<=num) times[i] = subtract(times[i],times[i ^ (1LL<<bit)]);
        }
    }

    for(ll i=0;i<=num;i++)cout<<times[i]<<" ";
    cout<<endl;

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