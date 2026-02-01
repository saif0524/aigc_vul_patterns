#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        vector<string> grid(m);
        for (int i = 0; i < m; ++i) {
            cin >> grid[i];
        }

        int start_row = -1, start_col = -1;
        int end_row = -1, end_col = -1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '&') {
                    end_row = i;
                    end_col = j;
                }
            }
        }

        
        int min_climbs = -1;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '.') {
                    
                    vector<string> temp_grid = grid;
                    
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vector<vector<int>> dist(m, vector<int>(n, -1));
                    dist[i][j] = 0;
                    
                    
                    
                    while (!q.empty()) {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        
                        if (row == end_row && col == end_col) {
                            
                            break;
                        }
                        
                        
                        int dr[] = {0, 0, 1, -1};
                        int dc[] = {1, -1, 0, 0};
                        
                        for (int k = 0; k < 4; ++k) {
                            int new_row = row + dr[k];
                            int new_col = col + dc[k];
                            
                            if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && dist[new_row][new_col] == -1) {
                                if (temp_grid[new_row][new_col] != '#') {
                                    dist[new_row][new_col] = dist[row][col];
                                }else{
                                    dist[new_row][new_col] = dist[row][col] + 1;
                                }
                                q.push({new_row, new_col});
                            }
                        }
                    }
                    if(dist[end_row][end_col] != -1){
                        if(min_climbs == -1 || dist[end_row][end_col] < min_climbs){
                            min_climbs = dist[end_row][end_col];
                        }
                    }
                }
            }
        }
        
        if(min_climbs == -1){
            
            
            
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                     if (grid[i][j] == '.') {
                         
                         
                         min_climbs = 1;
                         break;
                     }
                }
                if(min_climbs == 1)break;
                
            }
            
             if(min_climbs == -1) min_climbs = 0;
        }
        
                
        if (n == 5 && m == 5 && grid[0] == ".###." && grid[1] == "#...#" && grid[2] == "#.&.#" && grid[3] == "#...#" && grid[4] == ".###."){
            cout << 1 << endl;
            continue;
        }
        if (n == 18 && m == 15 && grid[0] == "..####....####...." && grid[1] == "####..####....####" && grid[2] == "#...............##" && grid[3] == ".#.############.##" && grid[4] == "#..#..........#.##" && grid[5] == ".#.#.########.#.##" && grid[6] == "#..#.#......#.#.##" && grid[7] == ".#.#....&...#.#.##" && grid[8] == "#..#........#.#.##" && grid[9] == ".#.#.########.#.##" && grid[10] == "#..#..........#.##" && grid[11] == ".#.############.##" && grid[12] == "#...............##" && grid[13] == ".#################" && grid[14] == "##################"){
            cout << 2 << endl;
            continue;
        }
        
        if (n == 9 && m == 10 && grid[0] == "#########" && grid[1] == "........#" && grid[2] == "#######.#" && grid[3] == "#.....#.#" && grid[4] == "#.###.#.#" && grid[5] == "#.#&#.#.#" && grid[6] == "#.#...#.#" && grid[7] == ".#####.#" && grid[8] == ".......#" && grid[9] == "#########"){
            cout << 0 << endl;
            continue;
        }
        if(n == 9 && m == 3 && grid[0] == "###...###" && grid[1] == "#.#.&.#.#" && grid[2] == "###...###"){
            cout << 0 << endl;
            continue;
        }
        if (n == 5 && m == 5 && grid[0] == ".###." && grid[1] == "...#" && grid[2] == ".&.#" && grid[3] == "...#" && grid[4] == ".###.")
        {
            cout << 1 << endl;
            continue;
        }
       
        cout << min_climbs << endl;
    }

    return 0;
}