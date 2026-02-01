#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        queue<pair<long long, int>> q;
        q.push({n, 0});
        map<long long, int> visited;
        visited[n] = 0;
        bool found = false;
        while (!q.empty()) {
            long long curr = q.front().first;
            int moves = q.front().second;
            q.pop();
            if (curr == 1) {
                cout << moves << endl;
                found = true;
                break;
            }
            if (curr % 6 == 0) {
                long long next = curr / 6;
                if (visited.find(next) == visited.end()) {
                    q.push({next, moves + 1});
                    visited[next] = moves + 1;
                }
            }
            long long next = curr * 2;
            if (next <= 1e9 && visited.find(next) == visited.end()) {
                q.push({next, moves + 1});
                visited[next] = moves + 1;
            }
        }
        if (!found) {
            cout << -1 << endl;
        }
    }
    return 0;
}