#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int res = 0;
    for (int i = 0; i < 25; i++) {
        vector<int> b;
        for (int j = 0; j < n; j++) {
            b.push_back(a[j] & ((1 << (i + 1)) - 1));
        }
        sort(b.begin(), b.end());
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            int l = j + 1, r = n;
            while (l < r) {
                int m = (l + r) / 2;
                if ((b[j] + b[m]) & ((1 << i) - 1)) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            cnt += n - l;
            if ((b[j] + b[j]) & ((1 << i) - 1)) {
                cnt--;
            }
        }
        cnt /= 2;
        if (cnt & 1) {
            res |= (1 << i);
        }
    }

    cout << res << endl;

    return 0;
}