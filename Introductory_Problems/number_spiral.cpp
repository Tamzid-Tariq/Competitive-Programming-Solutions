/*
Problem: Number Spiral
Link: https://cses.fi/problemset/task/1071/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int;

using ull = unsigned long long int;

using namespace std;

// vector<ll>vec;

// ll str[100][100];

ull checkerboard(ull row, ull column)
{

    // ll row,column;

    ull ans = 0;

    if ((row % 2 == 0) && (column <= row))
    {

        ans = (row * row + 1 - column);
    }

    else if ((row % 2 == 1) && (column <= row))
    {

        ans = (row - 1) * (row - 1) + column;
    }

    else if ((column % 2 == 1) && (column > row))
    {

        ans = (column * column + 1 - row);
    }

    else if ((column % 2 == 0) && (column > row))
    {

        ans = (column - 1) * (column - 1) + row;
    }

    return ans;
}

int main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);
    cout.tie(0);

    ll a;

    cin >> a;

    while (a--)
    {

        ull test, number;

        cin >> test >> number;

        cout << checkerboard(test, number) << endl;
    }

    return 0;
}