/*
Problem: Required Substring
Link: https://cses.fi/problemset/task/1112/
Author: Tamzid Tariq
Date: 2026-02-08
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

vector<ll>preftable;

void PrefixTable(string &need)
{
    ll siz = need.size();
    preftable.resize(siz+1);
    preftable[0] = -1;

    ll start = -1;

    for (ll i = 0; i < siz; i++)
    {
        while (start >= 0 && need[i] != need[start])
            start = preftable[start];
        start++;
        preftable[i+1] = start;
        // cout<<preftable[i+1]<<" ";
    }

}

vector<vector<ll>>dfa;

void build_automata(string &need)
{
    ll siz=need.size();
    dfa.resize(siz+1,vector<ll>(26));

    for(ll i=0;i<=siz;i++)
    {
        for(ll j=0;j<26;j++)
        {
            if(i==siz)dfa[i][j]=i;

            else 
            {
                ll start=i;
                while (start >= 0 && (char)('A'+j) != need[start])
                    start = preftable[start];
                start++;
                dfa[i][j] = start;
            }
        }
    }
}

void solve()
{
    ll num;
    cin>>num;

    string s;
    cin>>s;

    PrefixTable(s);
    build_automata(s);

    ll last=s.size();
    vector<vector<ll>>ans(num+1,vector<ll>(last+1));

    ans[0][0]=1;
    for(ll i=1;i<=num;i++)
    {
        for(ll j=0;j<=last;j++)
        {
            for(ll k=0;k<26;k++)
            {
                ll nxt=dfa[j][k];

                ans[i][nxt] =(ans[i][nxt] + ans[i-1][j])%modular;
            }
        }
    }
    cout<<ans[num][last]<<endl;
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