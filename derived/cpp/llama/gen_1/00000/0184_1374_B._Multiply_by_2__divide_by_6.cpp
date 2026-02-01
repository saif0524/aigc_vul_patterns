#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int bfs(int n) {
    if (n == 1) return 0;
    unordered_map<int, int> visited;
    queue<int> q;
    q.push(n);
    visited[n] = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr % 6 == 0 && visited.find(curr / 6) == visited.end()) {
            if (curr / 6 == 1) return visited[curr] + 1;
            q.push(curr / 6);
            visited[curr / 6] = visited[curr] + 1;
        }
        if (visited.find(curr * 2) == visited.end()) {
            q.push(curr * 2);
            visited[curr * 2] = visited[curr] + 1;
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << bfs(n) << endl;
    }
    return 0;
}