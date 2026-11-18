#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> ids(n);
    for (int i = 0; i < n; ++i) {
        cin >> ids[i];
    }
    
    long long total = 0;
    for (int i = 1; i <= n; ++i) {
        total += i;
        if (total >= k) {
            int pos = k - (total - i);
            cout << ids[pos - 1] << endl;
            return 0;
        }
    }
    
    return 0;
}