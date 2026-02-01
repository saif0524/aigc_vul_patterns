#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cnt1(5, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        ++cnt1[x];
    }

    vector<int> cnt2(5, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        ++cnt2[x];
    }

    int ans = 0;
    for (int i = 0; i < 5; ++i) {
        int d = abs(cnt1[i] - cnt2[i]);
        if (d % 2) {
            cout << -1 << endl;
            return 0;
        }
        ans += d / 2;
    }

    cout << ans << endl;

    return 0;
}