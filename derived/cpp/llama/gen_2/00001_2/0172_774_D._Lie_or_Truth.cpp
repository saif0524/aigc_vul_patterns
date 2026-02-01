#include <iostream>
using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    l--, r--;

    int a[105], b[105];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    bool is_same = true;
    for (int i = 0; i < n; i++) {
        if (i < l || i > r) {
            if (a[i] != b[i]) is_same = false;
        }
    }

    cout << (is_same ? "TRUTH" : "LIE") << endl;

    return 0;
}