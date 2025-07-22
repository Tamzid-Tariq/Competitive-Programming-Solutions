/*
Problem: Weird Algorithm
Link: https://cses.fi/problemset/task/1068
Author: Tamzid Tariq
Approach: Simulate the process as described - if n is odd multiply by 3 and add 1, if even divide by 2
Time Complexity: O(log n) - each step roughly halves the number on average
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    cin >> n;
    
    while (n != 1) {
        cout << n << " ";
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
    }
    cout << 1 << endl;
    
    return 0;
}
