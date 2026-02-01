#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    vector<long long> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    if (n == 2) {
        if (c[0] == t[0] && c[1] == t[1]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    }

    queue<vector<long long>> q;
    q.push(c);

    map<vector<long long>, bool> visited;
    visited[c] = true;

    while (!q.empty()) {
        vector<long long> current_c = q.front();
        q.pop();

        if (current_c == t) {
            cout << "Yes" << endl;
            return 0;
        }

        for (int i = 1; i < n - 1; ++i) {
            vector<long long> next_c = current_c;
            next_c[i] = current_c[i + 1] + current_c[i - 1] - current_c[i];

            if (visited.find(next_c) == visited.end()) {
                visited[next_c] = true;
                q.push(next_c);
            }
        }
    }

    cout << "No" << endl;

    return 0;
}