#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, c, d;
    cin >> n >> c >> d;

    vector<pair<int, int>> students(n);
    for (int i = 0; i < n; ++i) {
        cin >> students[i].first >> students[i].second;
    }

    long long good_teams = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int r1 = students[i].first - c;
                int w1 = students[i].second - d;
                int r2 = students[j].first - c;
                int w2 = students[j].second - d;
                int r3 = students[k].first - c;
                int w3 = students[k].second - d;

                if (r1 * w2 > r2 * w1 && r2 * w3 > r3 * w2 && r3 * w1 > r1 * w3) {
                    good_teams++;
                }
            }
        }
    }

    cout << good_teams << endl;

    return 0;
}