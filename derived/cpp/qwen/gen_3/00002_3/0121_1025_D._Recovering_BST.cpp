#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    
    for (int i = 0; i < n - 1; ++i) {
        if (gcd(a[i], a[i + 1]) == 1) {
            cout << "No";
            return 0;
        }
    }
    
    cout << "Yes";
    return 0;
}