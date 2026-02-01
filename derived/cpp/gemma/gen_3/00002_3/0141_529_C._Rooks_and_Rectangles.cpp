#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector<pair<int, int>> rooks(k);
    for (int i = 0; i < k; ++i) {
        cin >> rooks[i].first >> rooks[i].second;
    }

    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        bool protected_area = true;
        for (int x = x1; x <= x2; ++x) {
            for (int y = y1; y <= y2; ++y) {
                bool attacked = false;
                for (int j = 0; j < k; ++j) {
                    if ((rooks[j].first == x || rooks[j].second == y) &&
                        (x1 <= rooks[j].first && rooks[j].first <= x2) &&
                        (y1 <= rooks[j].second && rooks[j].second <= y2)) {
                        attacked = true;
                        break;
                    }
                }
                
                if (!attacked) {
                    protected_area = false;
                    break;
                }
            }
            if (!protected_area) break;
        }

        if (protected_area) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}