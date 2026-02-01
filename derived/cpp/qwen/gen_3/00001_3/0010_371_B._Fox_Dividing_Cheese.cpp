#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 0 << endl;
        return 0;
    }

    queue<pair<long long, int>> q;
    q.push({a, 0});
    q.push({b, 0});

    map<long long, int> visited;
    visited[a] = 0;
    visited[b] = 0;

    while (!q.empty()) {
        long long curr = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (curr == b) {
            cout << steps << endl;
            return 0;
        }

        if (curr % 2 == 0 && visited.find(curr / 2) == visited.end()) {
            q.push({curr / 2, steps + 1});
            visited[curr / 2] = steps + 1;
        }
        if (curr % 3 == 0 && visited.find(curr * 2 / 3) == visited.end()) {
            q.push({curr * 2 / 3, steps + 1});
            visited[curr * 2 / 3] = steps + 1;
        }
        if (curr % 5 == 0 && visited.find(curr * 4 / 5) == visited.end()) {
            q.push({curr * 4 / 5, steps + 1});
            visited[curr * 4 / 5] = steps + 1;
        }
    }

    cout << -1 << endl;

    return 0;
}