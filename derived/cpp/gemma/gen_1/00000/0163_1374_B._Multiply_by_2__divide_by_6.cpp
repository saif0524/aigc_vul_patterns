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

        int min_moves = -1;

        while (!q.empty()) {
            long long current_n = q.front().first;
            int current_moves = q.front().second;
            q.pop();

            if (current_n == 1) {
                min_moves = current_moves;
                break;
            }

            // Multiply by 2
            long long next_n_mul = current_n * 2;
            if (next_n_mul <= 1e9 && visited.find(next_n_mul) == visited.end()) {
                q.push({next_n_mul, current_moves + 1});
                visited[next_n_mul] = current_moves + 1;
            }

            // Divide by 6
            if (current_n % 6 == 0) {
                long long next_n_div = current_n / 6;
                if (visited.find(next_n_div) == visited.end()) {
                    q.push({next_n_div, current_moves + 1});
                    visited[next_n_div] = current_moves + 1;
                }
            }
        }

        cout << min_moves << endl;
    }

    return 0;
}