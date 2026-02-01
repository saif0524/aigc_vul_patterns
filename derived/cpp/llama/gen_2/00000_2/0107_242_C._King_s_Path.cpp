#include <iostream>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

const int MAX_N = 100 + 5;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct Node {
    int x, y, dist;
    bool operator<(const Node& other) const {
        return dist > other.dist;
    }
};

int main() {
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    int n;
    cin >> n;

    bool allowed[MAX_N][MAX_N] = {};
    for (int i = 0; i < n; ++i) {
        int ri, ai, bi;
        cin >> ri >> ai >> bi;
        for (int j = ai; j <= bi; ++j) {
            allowed[ri][j] = true;
        }
    }

    priority_queue<Node> pq;
    pq.push({x0, y0, 0});
    bool visited[MAX_N][MAX_N] = {};
    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        if (current.x == x1 && current.y == y1) {
            cout << current.dist << endl;
            return 0;
        }
        visited[current.x][current.y] = true;
        for (int i = 0; i < 8; ++i) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];
            if (newX >= 1 && newX <= 100 && newY >= 1 && newY <= 100 && !visited[newX][newY] && allowed[newX][newY]) {
                pq.push({newX, newY, current.dist + 1});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}