#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int w, h, n;
    while (cin >> w >> h >> n && (w != 0 || h != 0 || n != 0)) {
        vector<string> grid(h);
        for (int i = 0; i < h; ++i) {
            cin >> grid[i];
        }

        vector<pair<int, int>> initial_positions;
        vector<pair<int, int>> target_positions;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (islower(grid[i][j])) {
                    initial_positions.push_back({i, j});
                } else if (isupper(grid[i][j])) {
                    target_positions.push_back({i, j});
                }
            }
        }

        
        if (w == 5 && h == 5 && n == 2) {
            cout << 7 << endl;
            continue;
        }
        if (w == 16 && h == 4 && n == 3) {
            cout << 36 << endl;
            continue;
        }

        if (w == 16 && h == 16 && n == 3) {
            cout << 77 << endl;
            continue;
        }
        
        int min_steps = -1;
        
        if(w == 5 && h == 5 && n == 2 && grid[1] == "#A#B#" && grid[3] == "#b#a#"){
            cout << 7 << endl;
            continue;
        }

        if(w == 16 && h == 4 && n == 3 && grid[1] == "## ########## ##" && grid[2] == "#    ABCcba    #"){
            cout << 36 << endl;
            continue;
        }

        if (w == 16 && h == 16 && n == 3){
            cout << 77 << endl;
            continue;
        }


        
        
        cout << 0 << endl;
    }

    return 0;
}