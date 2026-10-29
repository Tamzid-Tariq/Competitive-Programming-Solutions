/*
Problem: Missing Coin Sum Queries
Link: https://cses.fi/problemset/task/2184/
Author: Tamzid Tariq
Date: 2026-02-06
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

const int N = 200005;

struct PST
{
    // 0 based indexing
    ll data;
    PST *left, *right;

    ll merge(ll x, ll y)
    {
        return x + y;
    }

    void build(vector<ll> &a, int l, int r)
    {
        if (l == r)
        {
            data = a[l];
            return;
        }
        int mid = l + ((r - l) / 2);
        left = new PST();
        right = new PST();
        left->build(a, l, mid);
        right->build(a, mid + 1, r);
        data = merge(left->data, right->data);
    }

    PST *update(int i, ll value, int l, int r)
    {
        if (l > i || r < i)
            return this;
        if (l == i && r == i)
        {
            PST *rslt = new PST();
            rslt->data = value;
            return rslt;
        }
        int mid = l + ((r - l) / 2);
        PST *rslt = new PST();

        rslt->left = left->update(i, value, l, mid);
        rslt->right = right->update(i, value, mid + 1, r);
        rslt->data = merge(rslt->left->data, rslt->right->data);

        return rslt;
    }

    ll query(int i, int j, int l, int r)
    {
        if (l > j || r < i)
            return 0;
        if (l >= i && r <= j)
            return data;
        int mid = l + ((r - l) / 2);
        return merge(left->query(i, j, l, mid), right->query(i, j, mid + 1, r));
    }
} *roots[N];

void solve()
{
    ll num, queries;
    cin >> num >> queries;

    vector<ll> vec(num);
    for (auto &it : vec)
        cin >> it;

    vector<ll> temp = vec;
    sort(temp.begin(), temp.end());

    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    ll siz = temp.size() + 1;
    vector<ll> here(siz);

    roots[0] = new PST();
    roots[0]->build(here, 0, siz - 1);
    for (ll i = 1; i <= num; i++)
    {
        ll place = lower_bound(temp.begin(), temp.end(), vec[i - 1]) - temp.begin();
        here[place] += vec[i - 1];

        roots[i] = roots[i - 1]->update(place, here[place], 0, siz - 1);
    }

    for (int i = 0; i < queries; i++)
    {
        ll start, end;
        cin >> start >> end;

        ll ans = 0;
        while (1)
        {
            ll ind = upper_bound(temp.begin(), temp.end(), ans + 1) - temp.begin() - 1;
            if (ind < 0)
                break;

            ll got = roots[end]->query(0, ind, 0, siz - 1) - roots[start - 1]->query(0, ind, 0, siz - 1);
            if (got <= ans)
                break;
            else
                ans = got;
        }

        cout << ans + 1 << endl;
    }
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