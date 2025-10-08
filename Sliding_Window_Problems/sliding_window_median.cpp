/*
Problem: Sliding Window Median
Link: https://cses.fi/problemset/task/1076/
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
    for (ll i = 0; i < num; i++)
    {
        cin >> vec[i];
        if (k == 1)
        {
            cout << vec[i] << " ";
            continue;
        }
        if (i == 0)
        {
            high.insert(vec[i]);
            bigsize++;
        }
        else
        {
            if (vec[i] > *(high.begin()))
            {
                high.insert(vec[i]);
                bigsize++;
                if ((bigsize - smallsize > 1) || (*(high.begin()) < *(low.rbegin())))
                {
                    ll temp = *(high.begin());
                    low.insert(temp);
                    high.erase(high.find(temp));
                    bigsize--;
                    smallsize++;
                }
                if ((smallsize - bigsize > 1))
                {
                    ll temp = *(low.rbegin());
                    high.insert(temp);
                    low.erase(low.find(temp));
                    smallsize--;
                    bigsize++;
                }
            }
            else
            {
                low.insert(vec[i]);
                smallsize++;
                if ((smallsize - bigsize > 1) || (*(high.begin()) > *(low.rbegin())))
                {
                    ll temp = *(low.rbegin());
                    high.insert(temp);
                    low.erase(low.find(temp));
                    smallsize--;
                    bigsize++;
                }
                if ((bigsize - smallsize > 1))
                {
                    ll temp = *(high.begin());
                    low.insert(temp);
                    high.erase(high.find(temp));
                    bigsize--;
                    smallsize++;
                }
            }
        }
        if (i + 1 >= k)
        {
            // cout<<endl;
            // for(auto it:high)cout<<it<<" ";cout<<endl;
            // for(auto it:low)cout<<it<<" ";cout<<endl;
            if (bigsize > smallsize)
            {
                cout << *(high.begin()) << " ";

                if (high.find(vec[i - k + 1]) == high.end())
                {
                    low.erase(low.find(vec[i - k + 1]));
                    smallsize--;
                }
                else
                {
                    high.erase(high.find(vec[i - k + 1]));
                    bigsize--;
                }
            }
            else
            {
                cout << *(low.rbegin()) << " ";

                if (low.find(vec[i - k + 1]) == low.end())
                {
                    high.erase(high.find(vec[i - k + 1]));
                    bigsize--;
                }
                else
                {
                    low.erase(low.find(vec[i + 1 - k]));
                    smallsize--;
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