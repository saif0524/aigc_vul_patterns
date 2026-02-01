#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 2005;

int n, m;
int a[MAX_N], b[MAX_N], c[MAX_N];

bool check(int x) {
    for (int i = 1; i <= n; ++i) {
        c[i] = (a[i] + x) % m;
    }
    sort(c + 1, c + n + 1);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i) {
        if (c[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        if (check(i)) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}