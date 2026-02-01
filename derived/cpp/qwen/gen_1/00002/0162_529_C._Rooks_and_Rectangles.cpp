#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector<pair<int, int>> rooks(k);
    for (int i = 0; i < k; ++i) {
        cin >> rooks[i].first >> rooks[i].second;
    }

    map<int, set<int>> row_rooks, col_rooks;
    for (const auto& rook : rooks) {
        row_rooks[rook.first].insert(rook.second);
        col_rooks[rook.second].insert(rook.first);
    }

    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        bool protected_area = true;

        for (auto it = row_rooks.lower_bound(x1); it != row_rooks.upper_bound(x2); ++it) {
            auto col_it = it->second.lower_bound(y1);
            if (col_it != it->second.end() && *col_it <= y2) {
                continue;
            }
            protected_area = false;
            break;
        }

        if (!protected_area) {
            for (auto it = col_rooks.lower_bound(y1); it != col_rooks.upper_bound(y2); ++it) {
                auto row_it = it->second.lower_bound(x1);
                if (row_it != it->second.end() && *row_it <= x2) {
                    continue;
                }
                protected_area = false;
                break;
            }
        }

        if (protected_area) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}