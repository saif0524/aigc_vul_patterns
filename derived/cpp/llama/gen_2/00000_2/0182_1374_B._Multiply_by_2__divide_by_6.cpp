#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        unordered_map<int, int> visited;
        queue<int> q;
        q.push(n);
        visited[n] = 0;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            if (current == 1) {
                cout << visited[current] << endl;
                break;
            }

            if (current % 6 == 0 && visited.find(current / 6) == visited.end()) {
                q.push(current / 6);
                visited[current / 6] = visited[current] + 1;
            }

            if (current * 2 <= 1000000000 && visited.find(current * 2) == visited.end()) {
                q.push(current * 2);
                visited[current * 2] = visited[current] + 1;
            }
        }

        if (q.empty()) {
            cout << -1 << endl;
        }
    }

    return 0;
}