/*
Problem: Nested Ranges Check
Link: https://cses.fi/problemset/task/2168/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
const ll modular = 1e9 + 7;
const double pi = acos(-1.0);

struct val
{
    ll start, end, index;
};

bool customsort(val first, val second)
{
    if (first.start == second.start)
        return first.end > second.end;

    return first.start < second.start;
}

void solve()
{
    ll num;
    cin >> num;

    vector<val> vec(num);
    for (ll i = 0; i < num; i++)
    {
        cin >> vec[i].start >> vec[i].end;
        vec[i].index = i;
    }
    sort(vec.begin(), vec.end(), customsort);

    ll ans[num + 2];
    ll miniy = LLONG_MAX;
    for (ll i = num - 1; i >= 0; i--)
    {
        if (vec[i].end < miniy)
        {
            ans[vec[i].index] = 0;
            miniy = vec[i].end;
        }
        else
            ans[vec[i].index] = 1;
    }
    for (ll i = 0; i < num; i++)
        cout << ans[i] << " ";
    cout << endl;
    ll maxiy = LLONG_MIN;

    for (ll i = 0; i < num; i++)
    {
        if (vec[i].end > maxiy)
        {
            ans[vec[i].index] = 0;
            maxiy = vec[i].end;
        }
        else
        {
            ans[vec[i].index] = 1;
        }
    }
    for (ll i = 0; i < num; i++)
        cout << ans[i] << " ";
    cout << endl;
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