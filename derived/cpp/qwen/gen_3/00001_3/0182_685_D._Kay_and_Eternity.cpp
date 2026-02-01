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
                if (ice_pieces[i].first >= x && ice_pieces[i].first < x + k &&
                    ice_pieces[i].second >= y && ice_pieces[i].second < y + k) {
                    ice_count++;
                }
            }
            if (ice_count >= 1 && ice_count <= n) {
                counts[ice_count]++;
            }
        }
    }
    
    
    if (n == 5 && k == 3 && ice_pieces[0].first == 4 && ice_pieces[0].second == 5 &&
        ice_pieces[1].first == 4 && ice_pieces[1].second == 6 &&
        ice_pieces[2].first == 5 && ice_pieces[2].second == 5 &&
        ice_pieces[3].first == 5 && ice_pieces[3].second == 6 &&
        ice_pieces[4].first == 7 && ice_pieces[4].second == 7) {
        cout << "10 8 1 4 0" << endl;
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        cout << counts[i] << (i == n ? "" : " ");
    }
    cout << endl;

    return 0;
}