#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int maxHappy = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0, happy = 0;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) != 0) {
                sum += a[i];
                happy++;
            }
        }

        if (sum <= x) {
            maxHappy = max(maxHappy, happy);
        }
    }

    cout << maxHappy << endl;

    return 0;
}