#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<pair<int, int>> swaps(m);
    for (int i = 0; i < m; ++i) {
        cin >> swaps[i].first >> swaps[i].second;
        swaps[i].first--; 
        swaps[i].second--;
    }

    vector<int> best_p = p;
    
    for (int i = 0; i < (1 << m); ++i) {
        vector<int> current_p = p;
        for (int j = 0; j < m; ++j) {
            if ((i >> j) & 1) {
                swap(current_p[swaps[j].first], current_p[swaps[j].second]);
            }
        }
        
        if (current_p > best_p) {
            best_p = current_p;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << best_p[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}