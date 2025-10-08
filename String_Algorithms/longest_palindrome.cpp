/*
Problem: Longest Palindrome
Link: https://cses.fi/problemset/task/1111/
Author: Tamzid Tariq
Date: 2025-10-08
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


struct Manacher
{
    vector<int>odd,even;
    ll num=0;
    string s;
    
    void build(string &given)
    {
        s=given;
        num=s.size();
        odd.resize(num),even.resize(num);

        int left=0,right=-1;

        for(int i=0;i<num;i++)
        {
            int k = i>right? 1:min(odd[left+right-i],right+1-i);

            while(i + k <num && i-k>=0 && s[i+k]==s[i-k])++k;
            odd[i]=k;

            if(i+k-1>right)left=i-k+1,right=i+k-1;
        }        

        left=0,right=-1;

        for(int i=0;i<num;i++)
        {
            int k=i>right?0:min(even[left+right-i+1],right-i+1);

            while(i+k < num && i-k-1 >=0 && s[i+k]==s[i-k-1])++k;
            even[i]=k;

            if(i+k-1 >right)left=i-k, right = i+k-1;
        }
    }

    void longest_palindrome()
    {
        ll max_len=0,start=0;

        for(int i=0;i<num;i++)
        {
            if(odd[i]*2-1>max_len)
            {
                max_len=odd[i]*2 -1;
                start=i+1-odd[i];
            }
            if(even[i]*2>max_len)
            {
                max_len=even[i]*2;
                start=i-even[i];
            }
        }

        cout<<s.substr(start,max_len)<<endl;
    }
};

void solve()
{
    string s;
    cin>>s;

    Manacher man;
    man.build(s);

    man.longest_palindrome();
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