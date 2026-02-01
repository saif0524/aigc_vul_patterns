#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> ice_pieces(n);
    for (int i = 0; i < n; ++i) {
        cin >> ice_pieces[i].first >> ice_pieces[i].second;
    }

    vector<int> counts(n + 1, 0);

    for (int x = -1000; x <= 1000; ++x) {
        for (int y = -1000; y <= 1000; ++y) {
            int ice_count = 0;
            for (int i = 0; i < n; ++i) {
                if (x <= ice_pieces[i].first && ice_pieces[i].first < x + k &&
                    y <= ice_pieces[i].second && ice_pieces[i].second < y + k) {
                    ice_count++;
                }
            }
            if (ice_count >= 1 && ice_count <= n) {
                counts[ice_count]++;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << counts[i] << (i == n ? "" : " ");
    }
    cout << endl;

    return 0;
}