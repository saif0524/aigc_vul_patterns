#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    
    long long l = 1, r = 2e12;
    while (l < r) {
        long long mid = (l + r) / 2;
        long long count = 0;
        for (long long i = 0; i < mid; ++i) {
            if (a[i % n] != b[i % m]) {
                count++;
                if (count >= k) break;
            }
        }
        if (count >= k) r = mid;
        else l = mid + 1;
    }
    cout << l;
}