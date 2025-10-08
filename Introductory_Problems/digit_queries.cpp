/*
Problem: Digit Queries
Link: https://cses.fi/problemset/task/2431/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int;
using ull = unsigned long long int;
using namespace std;
const ll maxi = 1e9 + 7;

vector<ll> PowerOfTen(19, 1);

void solve()
{
   ll index;
   cin >> index; // 19
   ll digitsSoFar = 0;
   ll digitsBeforeActualBlock = 0;
   ll numberOfDigits;

   for (ll i = 1; i < 19; i++)
   {
      digitsSoFar += (PowerOfTen[i] - PowerOfTen[i - 1]) * i;
      // i==1 -> 10 - 1 *1 =>9
      // i==2 -> (100 -10)*2 =>180 +9 =189
      // i==3 -> (1000-100)*3 =>2700 +189 =2889
      if (digitsSoFar >= index)
      {
         numberOfDigits = i; // 2
         break;
      }
      digitsBeforeActualBlock += (PowerOfTen[i] - PowerOfTen[i - 1]) * i;
      // while i==1; 1
      // i==2; 9
      // i==3; 180
   }
   ll smallestnum = PowerOfTen[numberOfDigits - 1]; // 10
   ll highestnum = PowerOfTen[numberOfDigits] - 1;  // 99
   ll ans = 0, startingPos_ans;

   while (smallestnum <= highestnum)
   {
      ll mid = (smallestnum + highestnum) / 2; // 54
      ll startingPos_mid = digitsBeforeActualBlock + 1 +
                           (mid - PowerOfTen[numberOfDigits - 1]) * numberOfDigits;
      // for i=2; 9 + 1 + (54-10)*2 = 98;

      if (startingPos_mid <= index)
      {
         if (mid > ans)
         {
            ans = mid;
            startingPos_ans = startingPos_mid;
         }
         smallestnum = mid + 1;
      }
      else if (index < startingPos_mid)
      {
         highestnum = mid - 1;
      }
   }
   string answer = to_string(ans);
   cout << answer[index - startingPos_ans] << endl;
}

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   for (ll i = 1; i < 19; i++)
   {
      PowerOfTen[i] = PowerOfTen[i - 1] * 10;
      // 0 -1; 1-10; 2-100; 3-1000; 4-10000;
   }
   ll n;
   cin >> n;
   while (n--)
   {
      solve();
   }
}