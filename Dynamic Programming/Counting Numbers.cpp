/*
Problem: Counting Numbers
Link: https://cses.fi/problemset/task/2220/
Author: Tamzid Tariq
Date: 2024-01-25
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

ll ans[20][12][2][2];

void solve()
{
    ll start,end;
    cin>>start>>end;

    memset(ans,-1,sizeof(ans));

    string s = to_string(end);

    function<ll(ll,ll,ll,ll)>go=[&](ll pos,ll last,ll edge,ll zero)
    {
        if(pos>=s.size())return 1LL;
        if(ans[pos][last][edge][zero]!=-1)return ans[pos][last][edge][zero];

        ll maxi=9;
        if(edge)
        {
            maxi=s[pos]-'0';
        }

        ll ret=0LL;
        for(ll i=0;i<=maxi;i++)
        {
            if(i+1==last && !zero)continue;

            ret+=(go(pos+1,i+1,(edge&(i==maxi)),zero&(i==0)));
        }

        // cout<<pos<<" "<<last-1<<" "<<edge<<" -> "<<ret<<endl;
        return ans[pos][last][edge][zero] = ret;
    };

    ll result = go(0,0,1,1);

    if(start)
    {

        memset(ans,-1,sizeof(ans));
        s = to_string(start-1);
        result -=go(0,0,1,1); 
    }

    cout<<result<<endl;
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