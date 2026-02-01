#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

const int MAX_N = 1e9;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }

        unordered_map<int, int> dist;
        queue<int> q;

        q.push(n);
        dist[n] = 0;

        bool found = false;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr % 6 == 0 && dist.find(curr / 6) == dist.end()) {
                q.push(curr / 6);
                dist[curr / 6] = dist[curr] + 1;

                if (curr / 6 == 1) {
                    cout << dist[curr / 6] << '\n';
                    found = true;
                    break;
                }
            }

            if (2 * curr <= MAX_N && dist.find(2 * curr) == dist.end()) {
                q.push(2 * curr);
                dist[2 * curr] = dist[curr] + 1;

                if (2 * curr == 1) {
                    cout << dist[2 * curr] << '\n';
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            cout << -1 << '\n';
        }
    }

    return 0;
}