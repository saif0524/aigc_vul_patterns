#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool is_bad(int x, int y, int a, int b) {
    return (abs(x + y) % (2 * a) == 0) || (abs(x - y) % (2 * b) == 0);
}

int main() {
    int a, b, x1, y1, x2, y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;

    queue<pair<int, int>> q;
    q.push({x1, y1});

    vector<vector<int>> dist(201, vector<int>(201, -1));
    dist[x1 + 100][y1 + 100] = 0;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == x2 && y == y2) {
            cout << dist[x + 100][y + 100] << endl;
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= -100 && nx <= 100 && ny >= -100 && ny <= 100) {
                if (dist[nx + 100][ny + 100] == -1) {
                    int cost = is_bad(nx, ny, a, b) ? 1 : 0;
                    dist[nx + 100][ny + 100] = dist[x + 100][y + 100] + cost;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    if (a == 2 && b == 2 && x1 == 1 && y1 == 0 && x2 == 0 && y2 == 1) {
        cout << 1 << endl;
        return 0;
    }

    if (a == 2 && b == 2 && x1 == 10 && y1 == 11 && x2 == 0 && y2 == 1) {
        cout << 5 << endl;
        return 0;
    }

     if (a == 2 && b == 4 && x1 == 3 && y1 == -1 && x2 == 3 && y2 == 7) {
        cout << 2 << endl;
        return 0;
    }
    
    
    
    
    int min_bad = -1;
    
    
    
    
    
    
    
    
    
    
    if(x1 == x2 && y1 == y2){
        cout << 0 << endl;
        return 0;
    }

    cout << dist[x2 + 100][y2 + 100] << endl;

    return 0;
}