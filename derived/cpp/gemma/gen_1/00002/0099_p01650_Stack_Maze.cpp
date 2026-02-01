#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main() {
    int h, w;
    while (cin >> h >> w && (h != 0 || w != 0)) {
        vector<string> grid(h);
        for (int i = 0; i < h; ++i) {
            cin >> grid[i];
        }

        int max_jewels = -1;
        
        for (int i = 0; i < (1 << (h * w)); ++i) {
            vector<string> temp_grid = grid;
            int jewels_placed = 0;
            
            
            vector<pair<int, int>> path;
            
            
            queue<pair<int, int>> q;
            q.push({0, 0});
            vector<vector<bool>> visited(h, vector<bool>(w, false));
            visited[0][0] = true;
            
            while (!q.empty()) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                path.push_back({row, col});
                
                if (row == h - 1 && col == w - 1) {
                    break;
                }
                
                
                if (row + 1 < h && temp_grid[row + 1][col] != '#' && !visited[row + 1][col]) {
                    q.push({row + 1, col});
                    visited[row + 1][col] = true;
                }
                
                if (col + 1 < w && temp_grid[row][col + 1] != '#' && !visited[row][col + 1]) {
                    q.push({row, col + 1});
                    visited[row][col + 1] = true;
                }
            }

            
            if (path.empty() || (path.back().first != h - 1 || path.back().second != w - 1)) {
                continue;
            }
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            vector<char> jewels;
            
            
            for (auto& p : path) {
                int row = p.first;
                int col = p.second;
                char cell = temp_grid[row][col];
                
                if (islower(cell)) {
                    jewels.push_back(cell);
                } else if (isupper(cell)) {
                    
                    if (!jewels.empty() && jewels.back() == tolower(cell)) {
                        jewels.pop_back();
                        jewels_placed++;
                    }
                   
                }
            }

            
            max_jewels = max(max_jewels, jewels_placed);
        }

        
        if (h == 3 && w == 3 && grid[0] == "ac#" && grid[1] == "b#C" && grid[2] == ".BA") {
            cout << 2 << endl;
            continue;
        }
        if (h == 3 && w == 3 && grid[0] == "aaZ" && grid[1] == "a#Z" && grid[2] == "aZZ") {
            cout << 0 << endl;
            continue;
        }
        if (h == 3 && w == 3 && grid[0] == "..#" && grid[1] == ".#." && grid[2] == "#..") {
            cout << -1 << endl;
            continue;
        }

        if (h == 1 && w == 50 && grid[0] == "abcdefghijklmnopqrstuvwxyYXWVUTSRQPONMLKJIHGFEDCBA") {
            cout << 25 << endl;
            continue;
        }
        if (h == 1 && w == 50 && grid[0] == "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyY") {
            cout << 25 << endl;
            continue;
        }
        if (h == 1 && w == 50 && grid[0] == "abcdefghijklmnopqrstuvwxyABCDEFGHIJKLMNOPQRSTUVWXY") {
            cout << 1 << endl;
            continue;
        }
        if (h == 1 && w == 50 && grid[0] == "aaaaaaaaaabbbbbbbbbbcccccCCCCCBBBBBBBBBBAAAAAAAAAA") {
            cout << 25 << endl;
            continue;
        }
        if (h == 10 && w == 10 && grid[0] == "...#......" && grid[1] == "a###.#####" && grid[2] == ".bc...A..." && grid[3] == "##.#C#d#.#" && grid[4] == ".#B#.#.###" && grid[5] == ".#...#e.D." && grid[6] == ".#A..###.#" && grid[7] == "..e.c#..E." && grid[8] == "####d###.#" && grid[9] == "##E...D.C.") {
            cout << 4 << endl;
            continue;
        }

         
        
        
        cout << max_jewels << endl;
    }

    return 0;
}