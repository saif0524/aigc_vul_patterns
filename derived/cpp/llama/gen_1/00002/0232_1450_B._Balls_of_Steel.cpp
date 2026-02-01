#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

int distance(const Point& p1, const Point& p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

bool is_connected(const vector<Point>& points, int k) {
    int n = points.size();
    vector<vector<bool>> graph(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && distance(points[i], points[j]) <= k) {
                graph[i][j] = true;
                graph[j][i] = true;
            }
        }
    }
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    for (bool v : visited) {
        if (!v) return false;
    }
    return true;
}

int get_min_operations(const vector<Point>& points, int k) {
    int n = points.size();
    if (!is_connected(points, k)) return -1;
    vector<vector<bool>> graph(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && distance(points[i], points[j]) <= k) {
                graph[i][j] = true;
                graph[j][i] = true;
            }
        }
    }
    int min_operations = numeric_limits<int>::max();
    for (int i = 0; i < n; i++) {
        vector<bool> visited(n, false);
        int operations = 0;
        queue<int> q;
        q.push(i);
        visited[i] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < n; v++) {
                if (!visited[v] && graph[u][v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        for (bool v : visited) {
            if (!v) {
                operations++;
                break;
            }
        }
        min_operations = min(min_operations, operations);
    }
    return min_operations;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<Point> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }
        int result = get_min_operations(points, k);
        cout << result << endl;
    }
    return 0;
}