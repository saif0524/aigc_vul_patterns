#include <bits/stdc++.h>
using namespace std;

int countSets(int n, int k, int s) {
    if (k == 0) return (s == 0) ? 1 : 0;
    if (n ==0) return 0;
    int count = countSets(n - 1, k, s);
    if (s >= n) count += countSets(n -1, k - 1, s - n);
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, s;
    while (cin >> n >> k >> s) {
        if (n ==0&& k == 0 && s == 0) break;
        cout << countSets(n, k, s) << "\n";
    }
    return 0;
}