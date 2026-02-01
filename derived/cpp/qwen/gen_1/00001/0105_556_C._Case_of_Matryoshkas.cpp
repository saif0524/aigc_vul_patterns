#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> chain_lengths;
    for (int i = 0; i < k; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int a;
            cin >> a;
        }
        chain_lengths.push_back(m);
    }
    int total_seconds = 0;
    for (int len : chain_lengths) {
        total_seconds += len - 1;
    }
    total_seconds += k - 1;
    cout << total_seconds;
}