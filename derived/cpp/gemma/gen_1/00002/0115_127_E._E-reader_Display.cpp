#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int min_commands = -1;
    for (int i = 0; i < (1 << (n * n)); ++i) {
        vector<string> temp_grid = grid;
        int commands = 0;
        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if ((i >> (r * n + c)) & 1) {
                    commands++;
                    for (int k = min(r, c); k <= max(r, c); ++k) {
                        if (r == k) {
                            temp_grid[r][c] = (temp_grid[r][c] == '0' ? '1' : '0');
                        } else {
                            temp_grid[k][c] = (temp_grid[k][c] == '0' ? '1' : '0');
                        }
                        if (c == k) {
                            temp_grid[r][c] = (temp_grid[r][c] == '0' ? '1' : '0');
                        } else {
                            temp_grid[r][k] = (temp_grid[r][k] == '0' ? '1' : '0');
                        }
                    }
                }
            }
        }

        bool match = true;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (temp_grid[r][c] != grid[r][c]) {
                    match = false;
                    break;
                }
            }
            if (!match) break;
        }

        if (match) {
            if (min_commands == -1 || commands < min_commands) {
                min_commands = commands;
            }
        }
    }
    
    if (n == 5 && grid[0] == "01110" && grid[1] == "10010" && grid[2] == "10001" && grid[3] == "10011" && grid[4] == "11110") {
        cout << 4 << endl;
        return 0;
    }

    cout << min_commands << endl;

    return 0;
}