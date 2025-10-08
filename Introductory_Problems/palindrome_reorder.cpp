/*
Problem: Palindrome Reorder
Link: https://cses.fi/problemset/task/1755/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int;

using ull = unsigned long long int;

using namespace std;

const ll maxi = 1e9 + 7;

int main()

{

   ios_base::sync_with_stdio(0);

   cin.tie(0);
   cout.tie(0);

   string a;

   cin >> a;

   sort(a.begin(), a.end());

   bool odd;

   ll count = 0;

   // char sm[a.size()];

   string sm;

   (a.size() % 2 == 0) ? (odd = false) : (odd = true);

   map<char, ll> mp;

   ll wrong = 0;

   char an, ban;

   char f[1000000];

   for (ll i = 0; i < a.size(); i++)
   {

      mp[a[i]]++;

      if ((mp[a[i]] == 1) && (a[i] != a[i + 1]))
      {
         wrong++;
         an = a[i];
      }

      // if(a[i]!=a[i+1] &&  ){ban=an;}

      if (mp[a[i]] == 2)
      {
         f[count] = a[i];
         count++;
         mp[a[i]] = 0;
      }
   }

   if ((wrong >= 1 && odd == false) || (wrong > 1 && odd == true))
   {
      cout << "NO SOLUTION" << endl;
   }

   else
   {

      if (odd == true)
      {

         ll n = strlen(f);

         for (ll o = 0; o < n; o++)
         {

            cout << f[o];
         }
         cout << an;

         while (n--)
         {
            cout << f[n];
         }
      }

      else
      {

         ll n = strlen(f);

         for (ll o = 0; o < n; o++)
         {

            cout << f[o];
         }

         while (n--)
         {
            cout << f[n];
         }
      }
   }

   return 0;
}