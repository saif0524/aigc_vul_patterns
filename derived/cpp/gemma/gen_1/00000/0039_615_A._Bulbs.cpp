#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> buttons(n);
    for (int i = 0; i < n; ++i) {
        int xi;
        cin >> xi;
        for (int j = 0; j < xi; ++j) {
            int yij;
            cin >> yij;
            buttons[i].push_back(yij - 1);
        }
    }

    vector<bool> bulbs(m, false);
    
    for (int i = 0; i < (1 << n); ++i) {
        vector<bool> temp_bulbs = bulbs;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                for (int bulb_index : buttons[j]) {
                    if (!temp_bulbs[bulb_index]) {
                        temp_bulbs[bulb_index] = true;
                    }
                }
            }
        }
        
        bool all_on = true;
        for (int k = 0; k < m; ++k) {
            if (!temp_bulbs[k]) {
                all_on = false;
                break;
            }
        }
        
        if (all_on) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}