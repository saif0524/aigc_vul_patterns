#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> weights;
    for (char c : s) {
        weights.push_back(c - 'a' + 1);
    }
    sort(weights.begin(), weights.end());
    int result = INT_MAX;
    bool found = false;
    for (int i = 0; i < (1 << n); ++i) {
        int count = 0;
        int sum = 0;
        int last = -2;
        bool valid = true;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                if (weights[j] <= last + 1) {
                    valid = false;
                    break;
                }
                last = weights[j];
                sum += weights[j];
                count++;
            }
        }
        if (valid && count == k) {
            result = min(result, sum);
            found = true;
        }
    }
    if (found) {
        cout << result << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}