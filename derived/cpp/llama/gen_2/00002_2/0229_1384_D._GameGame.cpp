#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int cnt[32] = {0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 32; j++) {
                if ((a[i] >> j) & 1) {
                    cnt[j]++;
                }
            }
        }
        bool win = false;
        for (int i = 31; i >= 0; i--) {
            if (cnt[i] % 2 == 1) {
                if (cnt[i] % 4 == 3 && (n - cnt[i]) % 2 == 0) {
                    win = false;
                } else {
                    win = true;
                }
                break;
            }
        }
        if (win) {
            cout << "WIN" << endl;
        } else {
            cout << "LOSE" << endl;
        }
    }
    return 0;
}