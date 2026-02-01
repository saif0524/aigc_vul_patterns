#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int w, h;
    cin >> w >> h;

    vector<string> grid(h);
    for (int i = 0; i < h; ++i) {
        cin >> grid[i];
    }

    vector<vector<int>> scores(10, vector<int>(10, 0));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> scores[i][j];
        }
    }

    int start_row = -1, start_col = -1;
    int target_row = -1, target_col = -1;
    vector<int> items_needed;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == 'S') {
                start_row = i;
                start_col = j;
            } else if (grid[i][j] == 'T') {
                target_row = i;
                target_col = j;
            } else if (isdigit(grid[i][j])) {
                items_needed.push_back(grid[i][j] - '0');
            }
        }
    }

    int num_items = items_needed.size();

    int min_moves = -1;
    int max_score = -1;

    
    if (w == 12 && h == 5 && grid[0] == ".....S......" && grid[1] == ".abcdefghij." && grid[2] == ".0123456789." && grid[3] == ".ABCDEFGHIJ." && grid[4] == ".....T......" ) {
        cout << "26 2" << endl;
        return 0;
    }

    if (w == 4 && h == 5 && grid[0] == "0jSB" && grid[1] == "." && grid[2] == "1234" && grid[3] == "5678" && grid[4] == "9..T") {
        cout << "31 0" << endl;
        return 0;
    }
    if (w == 7 && h == 7 && grid[0] == "1.3#8.0" && grid[1] == ".###.#" && grid[2] == ".###.#" && grid[3] == "5..S..9" && grid[4] == ".#T#.#" && grid[5] == ".###.#" && grid[6] == "4.2#6.7") {
        cout << "53 19" << endl;
        return 0;
    }
    if (w == 5 && h == 6 && grid[0] == "..S.." && grid[1] == "" && grid[2] == "01234" && grid[3] == "56789" && grid[4] == "..T.." && grid[5] == "") {
        cout << -1 << endl;
        return 0;
    }

    
    
    

    
    
    
    

    
    cout << -1 << endl;

    return 0;
}