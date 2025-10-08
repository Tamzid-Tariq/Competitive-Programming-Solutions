/*
Problem: Sliding Window Cost
Link: https://cses.fi/problemset/task/1077/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int;
using ull = unsigned long long int;
using namespace std;
const ll modular = 1e9 + 7;
const double pi = 22 / 7;

void solve()
{
    ll num, k;
    cin >> num >> k;
    vector<ll> vec(num);
    multiset<ll> low;
    multiset<ll> high;
    ll smallsize = 0;
    ll bigsize = 0;
    ll bigsum = 0, smallsum = 0;
    for (ll i = 0; i < num; i++)
    {
        cin >> vec[i];

        if (k == 1)
        {
            cout << 0 << " ";
            continue;
        }
        if (i == 0)
        {
            high.insert(vec[i]);
            bigsum += vec[i];
            bigsize++;
        }
        else
        {
            if (vec[i] > *(high.begin()))
            {
                high.insert(vec[i]);
                bigsize++;
                bigsum += vec[i];
                if ((bigsize - smallsize > 1) || (*(high.begin()) < *(low.rbegin())))
                {
                    ll temp = *(high.begin());
                    low.insert(temp);
                    high.erase(high.find(temp));
                    bigsize--;
                    smallsize++;
                    bigsum -= temp;
                    smallsum += temp;
                }
                if ((smallsize - bigsize > 1))
                {
                    ll temp = *(low.rbegin());
                    high.insert(temp);
                    low.erase(low.find(temp));
                    smallsize--;
                    bigsize++;
                    smallsum -= temp;
                    bigsum += temp;
                }
            }
            else
            {
                low.insert(vec[i]);
                smallsize++;
                smallsum += vec[i];
                if ((smallsize - bigsize > 1) || (*(high.begin()) > *(low.rbegin())))
                {
                    ll temp = *(low.rbegin());
                    high.insert(temp);
                    low.erase(low.find(temp));
                    smallsize--;
                    bigsize++;
                    smallsum -= temp;
                    bigsum += temp;
                }
                if ((bigsize - smallsize > 1))
                {
                    ll temp = *(high.begin());
                    low.insert(temp);
                    high.erase(high.find(temp));
                    bigsize--;
                    smallsize++;
                    bigsum -= temp;
                    smallsum += temp;
                }
            }
        }
        if (i + 1 >= k)
        {
            if (bigsize > smallsize)
            {
                ll median = *(high.begin());
                cout << (median * smallsize - smallsum) + (bigsum - median * bigsize) << " ";

                if (high.find(vec[i - k + 1]) == high.end())
                {
                    low.erase(low.find(vec[i - k + 1]));
                    smallsize--;
                    smallsum -= vec[i - k + 1];
                }
                else
                {
                    high.erase(high.find(vec[i - k + 1]));
                    bigsize--;
                    bigsum -= vec[i - k + 1];
                }
            }
            else
            {
                ll median = *(low.rbegin());
                cout << (median * smallsize - smallsum) + (bigsum - median * bigsize) << " ";

                if (low.find(vec[i - k + 1]) == low.end())
                {
                    high.erase(high.find(vec[i - k + 1]));
                    bigsize--;
                    bigsum -= vec[i - k + 1];
                }
                else
                {
                    low.erase(low.find(vec[i + 1 - k]));
                    smallsize--;
                    smallsum -= vec[i - k + 1];
                }
            }
        }
    }

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