#include <iostream>
#include <vector>

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
        
        for (int boulder_num = 0; boulder_num < k; ++boulder_num) {
            int current_pos = 0;
            
            while (current_pos < n - 1) {
                if (h[current_pos] >= h[current_pos + 1]) {
                    current_pos++;
                } else {
                    h[current_pos]++;
                    boulder_positions.push_back(current_pos + 1);
                    break;
                }
            }
            if (current_pos == n - 1) {
                boulder_positions.push_back(-1);
            }
        }
        
        if (boulder_positions[k - 1] == -1) {
            cout << -1 << endl;
        } else {
            cout << boulder_positions[k - 1] << endl;
        }
    }

    return 0;
}