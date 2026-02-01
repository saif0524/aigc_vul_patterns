#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

long long check(long long x, long long y) {
    if (y == 1) return 1;
    long long d = (x + y - 1) / y;
    if (x < y) {
        long long pos = x;
        long long diff = y - x;
        if ((diff % 2) == 0 && (diff / 2) <= (d - 1)) return diff / 2 + 1;
        else return 0;
    }
    if ((d * y) == x) return d;
    if ((x + y - 1) % y == 0) return d;
    if (((d - 1) * y) < x && ((d - 1) * y) + (d - 1) >= x) return d - 1;
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long res = n;
    for (int i = 0; i < (1 << n); i++) {
        vector<long long> b = a;
        long long pos = 0;
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) > 0) {
                b[j] = 1;
                pos++;
            }
        }
        long long temp = pos;
        for (int j = 0; j < n - 1; j++) {
            if (check(b[j], b[j + 1]) == 0) break;
            if (j == n - 2) {
                res = min(res, temp);
            }
        }
    }
    cout << res << endl;
    return 0;
}