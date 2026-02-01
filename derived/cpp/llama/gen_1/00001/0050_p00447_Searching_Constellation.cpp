#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int m;
    while (cin >> m) {
        if (m == 0) {
            break;
        }

        vector<pair<int, int>> constellation(m);
        for (int i = 0; i < m; i++) {
            cin >> constellation[i].first >> constellation[i].second;
        }

        int n;
        cin >> n;

        vector<pair<int, int>> stars(n);
        for (int i = 0; i < n; i++) {
            cin >> stars[i].first >> stars[i].second;
        }

        bool found = false;
        for (int i = 0; i < n; i++) {
            int dx = stars[i].first - constellation[0].first;
            int dy = stars[i].second - constellation[0].second;

            bool match = true;
            for (int j = 1; j < m; j++) {
                pair<int, int> star(constellation[j].first + dx, constellation[j].second + dy);
                if (find(stars.begin(), stars.end(), star) == stars.end()) {
                    match = false;
                    break;
                }
            }

            if (match) {
                cout << dx << " " << dy << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "No match found" << endl;
        }
    }

    return 0;
}