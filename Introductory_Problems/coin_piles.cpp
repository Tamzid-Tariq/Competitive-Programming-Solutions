/*
Problem: Coin Piles
Link: https://cses.fi/problemset/task/1754/
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

   ll a;

   cin >> a;

   while (a--)
   {

      ll one, two;

      cin >> one >> two;

      ll i;

      (one > two) ? (i = one - 2 * two) : (i = (two - 2 * one));

      if ((i <= 0) && ((one + two) % 3 == 0))
      {

         cout << "YES" << endl;
      }

      else
         cout << "NO" << endl;
   }

   return 0;
}