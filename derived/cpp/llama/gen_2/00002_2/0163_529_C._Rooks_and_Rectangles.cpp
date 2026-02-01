#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool operator<(const Point& a, const Point& b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int main() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector<Point> rooks(k);
    for (int i = 0; i < k; i++) {
        cin >> rooks[i].x >> rooks[i].y;
    }

    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        set<int> rows, cols;
        for (int j = 0; j < k; j++) {
            if (x1 <= rooks[j].x && rooks[j].x <= x2 && y1 <= rooks[j].y && rooks[j].y <= y2) {
                rows.insert(rooks[j].x);
                cols.insert(rooks[j].y);
            }
        }

        bool ok = true;
        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                if (rows.find(x) == rows.end() && cols.find(y) == cols.end()) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }

        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}