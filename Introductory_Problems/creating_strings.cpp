/*
Problem: Creating Strings
Link: https://cses.fi/problemset/task/1622/
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

    string n;

    cin >> n;

    sort(n.begin(), n.end());

    vector<string> permutation;

    permutation.push_back(n);

    while (next_permutation(n.begin(), n.end()) != 0)
    {

        // n=next.permutation(n.begin(),n.end());

        permutation.push_back(n);
    }

    cout << permutation.size() << endl;

    for (auto x : permutation)
    {

        cout << x << endl;
    }

    return 0;
}