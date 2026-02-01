#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    queue<pair<int, int>> q;
    unordered_map<int, bool> visited;
    q.push({a, 0});
    visited[a] = true;
    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();
        if (current == b) {
            cout << steps;
            return 0;
        }
        if (current * 2 <= b && !visited[current * 2]) {
            q.push({current * 2, steps + 1});
            visited[current * 2] = true;
        }
        if (current * 3 <= b && !visited[current * 3]) {
            q.push({current * 3, steps + 1});
            visited[current * 3] = true;
        }
        if (current * 5 <= b && !visited[current * 5]) {
            q.push({current * 5, steps + 1});
            visited[current * 5] = true;
        }
    }
    cout << -1;
    return 0;
}