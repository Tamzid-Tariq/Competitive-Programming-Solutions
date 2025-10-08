/*
Problem: Salary Queries
Link: https://cses.fi/problemset/task/1144/
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
const ll INF = 10000000000LL;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    ll num, query;
    cin >> num >> query;

    ordered_set os;

    vector<ll> vec(num);
    for (auto &it : vec)
    {
        cin >> it;
        os.insert(it);
    }

    while (query--)
    {
        char op;
        cin >> op;
        ll l, r;
        cin >> l >> r;

        if (op == '?')
        {
            ll maxi = os.order_of_key(r+1);
            ll mini = os.order_of_key(l);

            // cout<<maxi<<" "<<mini<<" -> ";
            // for(auto it:os)cout<<it<<" ";   
            // cout<<endl;
            // if (*os.find_by_order(maxi) == r)
            //     maxi++;
            // if (*os.find_by_order(mini) < l)
            //     mini++;
            // cout<<maxi<<" "<<mini<<endl;
            cout << maxi - mini  << endl;
        }
        else
        {
            os.insert(r);
            l--;
            // cout<<vec[l]<<endl<<endl;
            // for(auto it:os)cout<<it<<" "; cout<<endl;
            os.erase(os.find_by_order(os.order_of_key(vec[l])));
            vec[l] = r;
            
            // for(auto it:os)cout<<it<<" "; cout<<endl;
        }
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