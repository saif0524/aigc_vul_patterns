#include <bits/stdc++.h>
using namespace std;

int n, m, k, q;
set<int> rows[100005];
set<int> cols[100005];

struct Rectangle {
    int x1, y1, x2, y2;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k >> q;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        rows[x].insert(y);
        cols[y].insert(x);
    }

    for (int i = 0; i < q; i++) {
        Rectangle rect;
        cin >> rect.x1 >> rect.y1 >> rect.x2 >> rect.y2;
        bool isProtected = true;
        for (int x = rect.x1; x <= rect.x2; x++) {
            for (int y = rect.y1; y <= rect.y2; y++) {
                if (rows[x].lower_bound(y) == rows[x].end() || *rows[x].lower_bound(y) != y) {
                    if (cols[y].lower_bound(x) == cols[y].end() || *cols[y].lower_bound(x) != x) {
                        bool isCovered = false;
                        auto it = rows[x].lower_bound(y);
                        if (it != rows[x].begin()) {
                            it--;
                            if (*it < rect.y1) {
                                isCovered = true;
                            }
                        }
                        it = rows[x].upper_bound(y);
                        if (it != rows[x].end() && *it > rect.y2) {
                            isCovered = true;
                        }

                        if (!isCovered) {
                            it = cols[y].lower_bound(x);
                            if (it != cols[y].begin()) {
                                it--;
                                if (*it < rect.x1) {
                                    isCovered = true;
                                }
                            }
                            it = cols[y].upper_bound(x);
                            if (it != cols[y].end() && *it > rect.x2) {
                                isCovered = true;
                            }
                        }

                        if (!isCovered) {
                            isProtected = false;
                            break;
                        }
                    }
                }
            }
            if (!isProtected) {
                break;
            }
        }

        if (isProtected) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}