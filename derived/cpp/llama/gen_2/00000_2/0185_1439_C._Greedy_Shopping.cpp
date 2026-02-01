#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int n, q;
int arr[MAXN];

void update(int x, int y) {
    for (int i = 1; i <= x; i++) {
        arr[i] = max(arr[i], y);
    }
}

void query(int x, int y) {
    int ans = 0;
    for (int i = x; i <= n; i++) {
        if (y >= arr[i]) {
            ans++;
            y -= arr[i];
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    while (q--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            update(x, y);
        } else {
            query(x, y);
        }
    }
    return 0;
}