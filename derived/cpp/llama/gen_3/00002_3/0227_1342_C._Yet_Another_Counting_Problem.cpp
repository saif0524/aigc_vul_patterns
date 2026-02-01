#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count(int a, int b, int l, int r) {
    int res = 0;
    for (int x = l; x <= r; x++) {
        if (((x % a) % b) != ((x % b) % a)) {
            res++;
        }
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int a, b, q;
        cin >> a >> b >> q;
        for (int i = 0; i < q; i++) {
            long long l, r;
            cin >> l >> r;
            int res = 0;
            int len = min(200000ll, r - l + 1);
            for (long long x = 0; x < len; x++) {
                if (((x % a) % b) != ((x % b) % a)) {
                    res++;
                }
            }
            if (len < r - l + 1) {
                res += (r - l + 1 - len) * count(a, b, 0, len - 1) / len;
            }
            cout << res << endl;
        }
    }
    return 0;
}