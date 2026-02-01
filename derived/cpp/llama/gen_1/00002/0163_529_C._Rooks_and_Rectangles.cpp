#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector<pair<int, int>> rooks(k);
    for (auto& rook : rooks) {
        cin >> rook.first >> rook.second;
    }

    vector<set<int>> rows(n + 1), cols(m + 1);
    map<int, set<int>> rowRooks, colRooks;
    for (const auto& rook : rooks) {
        rows[rook.first].insert(rook.second);
        cols[rook.second].insert(rook.first);
        rowRooks[rook.first].insert(rook.second);
        colRooks[rook.second].insert(rook.first);
    }

    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        bool good = true;

        for (int x = x1; x <= x2; ++x) {
            for (int y = y1; y <= y2; ++y) {
                if (rows[x].count(y) == 0) {
                    bool found = false;
                    for (int ry = y1; ry <= y2; ++ry) {
                        if (rows[x].count(ry)) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        for (int rx = x1; rx <= x2; ++rx) {
                            if (cols[y].count(rx)) {
                                found = true;
                                break;
                            }
                        }
                    }
                    if (!found) {
                        good = false;
                        break;
                    }
                }
            }
            if (!good) {
                break;
            }
        }
        cout << (good ? "YES" : "NO") << endl;
    }

    return 0;
}