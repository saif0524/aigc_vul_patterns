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
                        (rooks[j].first >= x1 && rooks[j].first <= x2 &&
                         rooks[j].second >= y1 && rooks[j].second <= y2)) {
                        
                        bool blocked = false;
                        
                        if (rooks[j].first == x) {
                            for (int yy = min(rooks[j].second, y) + 1; yy < max(rooks[j].second, y); ++yy) {
                                for (int r = 0; r < k; ++r) {
                                    if (rooks[r].first == x && rooks[r].second == yy) {
                                        blocked = true;
                                        break;
                                    }
                                }
                                if (blocked) break;
                            }
                        } else {
                            for (int xx = min(rooks[j].first, x) + 1; xx < max(rooks[j].first, x); ++xx) {
                                for (int r = 0; r < k; ++r) {
                                    if (rooks[r].second == y && rooks[r].first == xx) {
                                        blocked = true;
                                        break;
                                    }
                                }
                                if (blocked) break;
                            }
                        }
                        
                        if (!blocked) {
                            attacked = true;
                            break;
                        }
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