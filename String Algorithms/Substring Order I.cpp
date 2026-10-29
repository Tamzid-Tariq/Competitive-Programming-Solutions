/*
Problem: Substring Order I
Link: https://cses.fi/problemset/task/2108/
Author: Tamzid Tariq
Date: 2026-02-10
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

struct SuffixArray
{
    ll num;
    vector<ll> clas, sorted, temp, lcp;
    string s;
    // sparsetable ST;

    void build(string &st)
    {
        s = st;
        s += '$';
        num = s.size();

        clas.resize(num), sorted.resize(num), lcp.resize(num);

        iota(sorted.begin(), sorted.end(), 0LL);

        sort(sorted.begin(), sorted.end(), [&](ll ind1, ll ind2)
             { return s[ind1] < s[ind2]; });

        clas[sorted[0]] = 0;

        for (ll i = 1; i < num; i++)
        {
            clas[sorted[i]] = clas[sorted[i - 1]] + (s[sorted[i]] != s[sorted[i - 1]]);
        }

        ll k = 0;

        while ((1LL << k) < num)
        {
            sort(sorted.begin(), sorted.end(), [&](ll ind, ll ind2)
                 { return (make_pair(clas[ind], clas[(ind + (1LL << k)) % num]) < make_pair(clas[ind2], clas[(ind2 + (1LL << k)) % num])); });

            temp = clas;
            temp[sorted[0]] = 0;
            for (ll i = 1; i < num; i++)
            {
                temp[sorted[i]] = temp[sorted[i - 1]] + (make_pair(clas[sorted[i]], clas[(sorted[i] + (1LL << k)) % num]) != make_pair(clas[sorted[i - 1]], clas[(sorted[i - 1] + (1LL << k)) % num]));
            }

            clas = temp;

            k++;
        }

        k = 0;

        for (ll i = 0; i < num - 1; i++)
        {
            ll pi = clas[i];
            ll j = sorted[pi - 1];

            while (s[i + k] == s[j + k])
                k++;

            lcp[pi] = k;
            k = max(0LL, k - 1);
        }

        // ST.initialize(num + 1);
        // ST.build(sorted);
    }
};

void solve()
{
    string s;
    cin>>s;

    ll times;
    cin>>times;

    SuffixArray SA;
    SA.build(s);

    ll need=times,num=s.size();

    for(ll i=1;i<=num;i++)
    {
        if(times<=(num - SA.sorted[i]) - SA.lcp[i])
        {
            cout<<s.substr(SA.sorted[i],SA.lcp[i] + times)<<endl;
            return;
        }
        
        times-= (num - SA.sorted[i]) - SA.lcp[i];
    }

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