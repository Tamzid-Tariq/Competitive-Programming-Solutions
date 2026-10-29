/*
Problem: Advertisement
Link: https://cses.fi/problemset/task/1142/
Author: Tamzid Tariq
Date: 2026-02-09
Status: Accepted ✓
*/

#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
#define endl '\n';
const ll modular = 1e9 + 7;
const double pi = acos(-1.0);
const ll INF = 1e18;

void solve()
{
    ll num;
    cin >> num;

    vector<ll> vec(num + 1);
    for (ll i = 1; i <= num; i++)
        cin >> vec[i];

    stack<ll> st;
    vector<ll> left(num + 1), right(num + 1);
    for (ll i = 1; i <= num; i++)
    {
        while (st.size() && vec[st.top()] >= vec[i])
            st.pop();

        left[i] = (st.empty() ? 0 : st.top());
        st.push(i);
    }

    while (!st.empty())
        st.pop();

    for (ll i = num; i >= 1; i--)
    {
        while (st.size() && vec[st.top()] >= vec[i])
            st.pop();

        right[i] = (st.empty() ? num + 1 : st.top());
        st.push(i);
    }

    ll ans = *max_element(vec.begin(), vec.end());

    for (ll i = 1; i <= num; i++)
    {
        ans = max(ans, vec[i] * (right[i] - left[i] - 1));
    }

    cout << ans << endl;
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