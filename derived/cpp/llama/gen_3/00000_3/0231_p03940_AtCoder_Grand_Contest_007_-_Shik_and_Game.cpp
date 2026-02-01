#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e, t;
    cin >> n >> e >> t;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    long long time = 0;
    long long pos = 0;
    for (int i = 0; i < n; i++) {
        long long dt = x[i] - pos;
        time += dt;
        pos = x[i];
        if (time <= t * (n - i - 1)) {
            time += t;
        }
    }
    cout << time + (e - pos) << endl;

    return 0;
}