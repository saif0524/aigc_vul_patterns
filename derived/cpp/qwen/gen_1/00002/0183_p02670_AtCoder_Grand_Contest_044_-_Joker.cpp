#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> P(N*N);
    for(int &x: P) cin >> x;
    vector<vector<int>> grid(N, vector<int>(N));
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            grid[i][j] = i*N+j+1;
        }
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int visited[505][505] = {0};
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            pq.push({0, {i, j}});
        }
    }
    int result = 0;
    for(int i=0; i<N*N; ++i){
        int x, y;
        while(pq.size() && visited[x = pq.top().second.first][y = pq.top().second.second]){
            pq.pop();
        }
        visited[x][y] = 1;
        int pos = x*N + y + 1;
        for(int j=i+1; j<N*N; ++j){
            int nx = (P[j] - 1) / N, ny = (P[j] - 1) % N;
            if(visited[nx][ny]) continue;
            bool found = false;
            for(int k=0; k<4; ++k){
                int xx = x + dx[k], yy = y + dy[k];
                if(xx < 0 || yy < 0 || xx >= N || yy >= N) continue;
                if(grid[xx][yy] == P[j]){
                    found = true;
                    break;
                }
            }
            if(!found) result++;
        }
        for(int k=0; k<4; ++k){
            int nx = x + dx[k], ny = y + dy[k];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            pq.push({pos, {nx, ny}});
        }
    }
    cout << result;
}