#include <bits/stdc++.h>

using namespace std;

const int MAXN = 101;

int a[MAXN];
map<int, int> depth;

void buildTree(int l, int r, int d) {
    if (l > r) return;
    int maxIdx = l;
    for (int i = l; i <= r; i++) {
        if (a[i] > a[maxIdx]) maxIdx = i;
    }
    depth[a[maxIdx]] = d;
    buildTree(l, maxIdx - 1, d + 1);
    buildTree(maxIdx + 1, r, d + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        depth.clear();
        buildTree(0, n - 1, 0);
        for (int i = 0; i < n; i++) {
            cout << depth[a[i]] << " ";
        }
        cout << "\n";
    }

    return 0;
}