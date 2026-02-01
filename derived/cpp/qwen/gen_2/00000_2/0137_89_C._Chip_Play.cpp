#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
char dir[] = {'L', 'R', 'U', 'D'};

int n, m;
char grid[5005][5005];
bool visited[5005][5005];
int scores[5005][5005];
int maxScore = 0, countMaxScore = 0;

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '.';
}

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    int score = 0;
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        if (visited[cx][cy]) continue;
        visited[cx][cy] = true;
        score++;
        char d = grid[cx][cy];
        for (int i = 0; i < 4; i++) {
            if (dir[i] != d) continue;
            int nx = cx, ny = cy;
            int step = 0;
            while (isValid(nx + dx[i], ny + dy[i])) {
                nx += dx[i];
                ny += dy[i];
                step++;
            }
            if (step) {
                q.push({nx, ny});
            }
        }
    }
    return score;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] != '.'){
                if(scores[i][j] == 0){
                    int score = bfs(i, j);
                    if(score > maxScore){
                        maxScore = score;
                        countMaxScore = 1;
                    }
                    else if(score == maxScore){
                        countMaxScore++;
                    }
                }
            }
        }
    }
    cout << maxScore << " " << countMaxScore;
}