#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int N = 10;
const int M = 5;

string a[N];

bool check(const string& a, const string& b) {
    for (int i = 0; i < M; ++i) {
        if (a[i] == b[M - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    string line;
    while (getline(cin, line) && line != "END") {
        for (int i = 0; i < N; ++i) {
            size_t pos = line.find(' ');
            a[i] = line.substr(0, pos);
            line = line.substr(pos + 1);
        }

        vector<vector<int>> g(N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (check(a[i], a[j])) {
                    g[i].push_back(j);
                }
            }
        }

        int cnt = 0;
        vector<int> vis(N, 0);
        vector<int> matching(N, -1);

        function<bool(int)> dfs = [&](int u) {
            for (int v : g[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    if (matching[v] == -1 || dfs(matching[v])) {
                        matching[v] = u;
                        return true;
                    }
                }
            }
            return false;
        };

        for (int i = 0; i < N; ++i) {
            fill(vis.begin(), vis.end(), 0);
            if (dfs(i)) {
                ++cnt;
            }
        }

        int ans = 1;
        for (int i = 0; i < cnt / 2; ++i) {
            ans *= 2;
        }

        cout << ans * 24 / 4 << '\n';
    }
    return 0;
}