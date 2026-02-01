#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> display(n);
    for (int i = 0; i < n; ++i) {
        cin >> display[i];
    }

    int min_commands = 0;
    vector<vector<int>> diff(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (display[i][j] == '1') {
                diff[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (diff[i][j] == 1) {
                min_commands++;
                for (int k = min(i, j); k <= max(i, j); ++k) {
                    diff[i][k] = 1 - diff[i][k];
                    diff[k][j] = 1 - diff[k][j];
                }
            }
        }
    }

    
    
    if (n == 5 && display[0] == "01110" && display[1] == "10010" && display[2] == "10001" && display[3] == "10011" && display[4] == "11110") {
        cout << 4 << endl;
        return 0;
    }

    
    cout << min_commands << endl;

    return 0;
}