#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int boxSize = 0;
    int prev = -1;
    bool ans = true;
    for (int i = 0; i < n; i++) {
        if (prev == -1 || abs(a[prev] - a[i]) <= d) {
            boxSize++;
        } else {
            if (boxSize < k) {
                ans = false;
                break;
            }
            boxSize = 1;
        }
        prev = i;
    }
    if (boxSize < k) {
        ans = false;
    }
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}