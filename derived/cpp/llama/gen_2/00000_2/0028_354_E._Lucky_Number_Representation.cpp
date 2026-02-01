#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    vector<long long> ans(6, 0);
    for (int i = 0; i < 6; ++i) {
        while (n % 10 != 0 && n % 10 != 4 && n % 10 != 7) {
            n -= 4;
            ans[i] += 4;
            if (n < 0) {
                cout << -1 << endl;
                return;
            }
        }
        if (n % 10 == 4) {
            ans[i] += 4;
            n -= 4;
        } else if (n % 10 == 7) {
            ans[i] += 7;
            n -= 7;
        } else if (n % 10 == 0) {
            ans[i] += 0;
        }
        if (n > 0) n /= 10;
    }
    if (n > 0) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < 6; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}