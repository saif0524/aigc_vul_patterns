#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int m, n;
    while (cin >> m && m != 0) {
        vector<pair<int, int>> constellation(m);
        for (int i = 0; i < m; ++i) {
            cin >> constellation[i].first >> constellation[i].second;
        }
        cin >> n;
        vector<pair<int, int>> photo(n);
        for (int i = 0; i < n; ++i) {
            cin >> photo[i].first >> photo[i].second;
        }
        unordered_map<int, int> delta_x_count, delta_y_count;
        for (auto& star1 : constellation) {
            for (auto& star2 : photo) {
                int dx = star2.first - star1.first;
                int dy = star2.second - star1.second;
                ++delta_x_count[dx];
                ++delta_y_count[dy];
            }
        }
        int max_dx = 0, max_dy = 0;
        for (auto& p : delta_x_count) {
            if (p.second > delta_x_count[max_dx]) {
                max_dx = p.first;
            }
        }
        for (auto& p : delta_y_count) {
            if (p.second > delta_y_count[max_dy]) {
                max_dy = p.first;
            }
        }
        cout << max_dx << " " << max_dy << endl;
    }
    return 0;
}