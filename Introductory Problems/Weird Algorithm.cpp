/*
Problem: Weird Algorithm
Link: https://cses.fi/problemset/task/1068/
Author: Tamzid Tariq
Date: 2023-02-13
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int ;
using ull=unsigned long long int;
using namespace std;


 int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);


    ll a;
    cin>>a;
    cout<<a<<" ";
   while(a>1){if(a==1){break;}
    if(a&1){a=(a*3)+1;cout<<a<<" ";}
    else {a/=2; cout<<a<<" ";}


   }
 return 0;
}
