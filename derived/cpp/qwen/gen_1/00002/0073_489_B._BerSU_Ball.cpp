#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    cin >> m;
    vector<int> b(m);
    for (auto &x : b) cin >> x;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int i = 0, j = 0, cnt = 0;
    while (i < n && j < m) {
        if (abs(a[i] - b[j]) <= 1) {
            cnt++;
            i++;
            j++;
        } else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }
    
    cout << cnt;
}