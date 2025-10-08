/*
Problem: String Matching
Link: https://cses.fi/problemset/task/1753/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
const ll modular = 1e9 + 7;
const double pi = acos(-1.0);
const ll INF = 10000000000LL;


void PrefixTable(string need, vector<ll>&preftable)
{
    ll siz = need.size();

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

void KMPSearch(string given, string need,vector<ll>&PrefixTable)
{
    ll start1=0,start2=0,siz1=given.size(),siz2=need.size();

    vector<ll>matchingindex;

    while(start1<siz1)
    {
        while(start2>=0 && given[start1]!=need[start2]) start2=PrefixTable[start2];
        start1++,start2++;
        if(start2==siz2)
        {
            matchingindex.push_back(start1-start2+1);
            start2=PrefixTable[start2];
        }
    }

    cout<<matchingindex.size()<<endl;
    // for(auto it:matchingindex)cout<<it<<" ";
}

void solve()
{
    string one, two;
    cin >> one >> two;

    // cout<<one<<" "<<two<<endl;
    vector<ll> preftable(two.size() + 1, 0);
    PrefixTable(two,preftable);
    KMPSearch(one,two,preftable);
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