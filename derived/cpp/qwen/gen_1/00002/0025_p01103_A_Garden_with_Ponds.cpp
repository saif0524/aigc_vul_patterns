#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main(){
    int d, w;
    while(cin >> d >> w && (d || w)){
        vector<vector<int>> grid(d, vector<int>(w));
        for(int i=0; i<d; ++i){
            for(int j=0; j<w; ++j){
                cin >> grid[i][j];
            }
        }
        int max_capacity = 0;
        for(int x1=0; x1<d-2; ++x1){
            for(int y1=0; y1<w-2; ++y1){
                for(int x2=x1+2; x2<d; ++x2){
                    for(int y2=y1+2; y2<w; ++y2){
                        int min_outer = 10;
                        for(int i=x1; i<=x2; ++i){
                            for(int j=y1; j<=y2; ++j){
                                if(i == x1 || i == x2 || j == y1 || j == y2){
                                    min_outer = min(min_outer, grid[i][j]);
                                }
                            }
                        }
                        queue<pair<int, int>> q;
                        for(int i=x1+1; i<x2; ++i){
                            for(int j=y1+1; j<y2; ++j){
                                q.push({i, j});
                            }
                        }
                        int capacity = 0;
                        bool valid = true;
                        vector<vector<int>> visited(d, vector<int>(w, 0));
                        while(!q.empty()){
                            int x = q.front().first;
                            int y = q.front().second;
                            q.pop();
                            if(visited[x][y]) continue;
                            visited[x][y] = 1;
                            if(grid[x][y] >= min_outer){
                                valid = false;
                                break;
                            }
                            capacity += min_outer - grid[x][y];
                            for(int dir=0; dir<4; ++dir){
                                int nx = x + dx[dir];
                                int ny = y + dy[dir];
                                if(nx >= x1+1 && nx <= x2-1 && ny >= y1+1 && ny <= y2-1 && !visited[nx][ny]){
                                    q.push({nx, ny});
                                }
                            }
                        }
                        if(valid){
                            max_capacity = max(max_capacity, capacity);
                        }
                    }
                }
            }
        }
        cout << max_capacity << endl;
    }
    return 0;
}