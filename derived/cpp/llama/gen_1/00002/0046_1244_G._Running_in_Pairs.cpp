#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += i;
    }

    if (ans > k) {
        cout << -1 << endl;
        return 0;
    }

    int s = n, l = n, r = 1;
    int a[n], b[n];
    for (int i = 0; i < n; ++i) {
        if (s + l <= k) {
            a[i] = l;
            b[i] = r;
            s += l;
            l--;
            r++;
        } else {
            l = r - 1;
            a[i] = l;
            b[i] = r;
            s += l;
            l--;
        }
    }

    cout << s << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}