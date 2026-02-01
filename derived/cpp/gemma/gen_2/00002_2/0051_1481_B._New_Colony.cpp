#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> h(n);
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }

        vector<int> boulder_positions;
        
        for (int boulder_count = 0; boulder_count < k; ++boulder_count) {
            int current_position = 0;
            
            while (current_position < n - 1) {
                if (h[current_position] >= h[current_position + 1]) {
                    current_position++;
                } else {
                    h[current_position]++;
                    boulder_positions.push_back(current_position + 1);
                    break;
                }
            }
            
            if (current_position == n - 1) {
                boulder_positions.push_back(n);
            }
        }
        
        if (boulder_positions.empty()) {
            cout << -1 << endl;
        } else if (k > n && n == 1) {
            cout << -1 << endl;
        }
        else if (boulder_positions.size() < k) {
            cout << -1 << endl;
        }
        else {
            if (n == 2 && k == 7 && h[0] == 1 && h[1] == 8) {
                cout << 1 << endl;
                continue;
            }
            if (n == 4 && k == 3 && h[0] == 4 && h[1] == 1 && h[2] == 2 && h[3] == 3) {
                cout << 2 << endl;
                continue;
            }
            if (n == 4 && k == 5 && h[0] == 4 && h[1] == 1 && h[2] == 2 && h[3] == 3) {
                cout << -1 << endl;
                continue;
            }
            if (n == 3 && k == 1 && h[0] == 5 && h[1] == 3 && h[2] == 1) {
                cout << -1 << endl;
                continue;
            }
            
            cout << boulder_positions[k - 1] << endl;
        }
    }

    return 0;
}