#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int max_suffix[n], max_prefix[n];
    max_suffix[n-1] = a[n-1];
    for (int i = n-2; i >= 0; --i)
        max_suffix[i] = max(a[i], max_suffix[i+1] + a[i]);

    max_prefix[0] = a[0];
    for (int i = 1; i < n; ++i)
        max_prefix[i] = max(a[i], max_prefix[i-1] + a[i]);

    int ans = INT_MIN;
    for (int i = 0; i < n; ++i) {
        int score = 0;
        if (i > 0)
            score = max(score, max_suffix[i-1] - a[i]);
        if (i < n-1)
            score = max(score, max_prefix[i+1] - a[i]);
        ans = max(ans, score);
    }

    cout << max(ans, 0) << endl;
}