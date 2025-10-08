/*
Problem: Repetitions
Link: https://cses.fi/problemset/task/1069/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int;

using ull = unsigned long long int;

using namespace std;
int main()
{

   ios_base::sync_with_stdio(0);

   cin.tie(0);
   cout.tie(0);

   string as;

   cin >> as;

   ll a;
   a = as.size();

   ll count = 0;

   ll max = 0;

   char num[a + 1];

   for (ll i = 1; i < a; i++)
   {

      if (as[i] == as[i - 1])
      {

         count++;
         count > max ? (max = count) : 0;
      }

      else
      {

         count = 0;
      }
   }

   cout << max + 1 << endl;

   return 0;
}