/*
Problem: Tower of Hanoi
Link: https://cses.fi/problemset/task/2165/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

ll counting(ll x)
{

     if (x == 1)
     {
          return 1;
     }

     else
     {
          return (2 * (counting(x - 1)) + 1);
     }

     // return y;
}

void pm(ll start, ll end)
{

     cout << start << " " << end << endl;
}

void hanoi(ll n, ll start, ll end)
{

     if (n == 1)
     {
          pm(start, end);
     }

     else
     {
          ll other = 6 - start - end;

          hanoi(n - 1, start, other);

          pm(start, end);

          hanoi(n - 1, other, end);
     }
}

int main()
{

     ios_base::sync_with_stdio(0);

     cin.tie(0);
     cout.tie(0);

     ll n;

     cin >> n;

     cout << counting(n) << endl;

     hanoi(n, 1, 3);

     return 0;
}