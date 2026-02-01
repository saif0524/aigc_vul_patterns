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
        long long current_val = q.front().first;
        int current_ops = q.front().second;
        q.pop();

        if (visited.count(b) && current_val == b) {
            cout << current_ops << endl;
            return 0;
        }
        
        if (current_val % 2 == 0 && !visited.count(current_val / 2)) {
            q.push({current_val / 2, current_ops + 1});
            visited[current_val / 2] = current_ops + 1;
        }
        if (current_val % 3 == 0 && !visited.count(current_val * 2 / 3)) {
            q.push({current_val * 2 / 3, current_ops + 1});
            visited[current_val * 2 / 3] = current_ops + 1;
        }
        if (current_val % 5 == 0 && !visited.count(current_val * 4 / 5)) {
            q.push({current_val * 4 / 5, current_ops + 1});
            visited[current_val * 4 / 5] = current_ops + 1;
        }
        
        if(current_val == 0 || current_ops > 100)
        {
            
        }
    }

    cout << -1 << endl;

    return 0;
}