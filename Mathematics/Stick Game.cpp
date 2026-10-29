/*
Problem: Stick Game
Link: https://cses.fi/problemset/task/1729/
Author: Tamzid Tariq
Date: 2026-02-14
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


void solve()
{
    ll total,num;
    cin>>total>>num;

    vector<ll>vec(num),ans(total+2);

    for(auto &it:vec)
    {
        cin>>it;
        ans[it]=1;
    }

    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());


    for(ll i=1;i<=total;i++)
    {
        if(!ans[i])
        {
            for(auto it:vec)
            {
                if(it<i && !ans[i-it])ans[i]=1;
            }
        }

        cout<<(ans[i]?"W":"L");
    }
    cout<<endl;
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