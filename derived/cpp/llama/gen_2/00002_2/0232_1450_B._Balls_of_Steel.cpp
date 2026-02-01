#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_N = 100;
const int MAX_K = 1000000;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].first >> points[i].second;
        }

        bool possible = false;
        for (int i = 0; i < n; i++) {
            int count = 1;
            for (int j = 0; j < n; j++) {
                if (i!= j && abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second) <= k) {
                    count++;
                }
            }
            if (count == n) {
                possible = true;
                break;
            }
        }

        if (!possible) {
            cout << -1 << endl;
            continue;
        }

        int ans = n;
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            queue<int> q;
            q.push(i);
            visited[i] = true;
            int count = 1;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int j = 0; j < n; j++) {
                    if (!visited[j] && abs(points[curr].first - points[j].first) + abs(points[curr].second - points[j].second) <= k) {
                        q.push(j);
                        visited[j] = true;
                        count++;
                    }
                }
            }

            if (count == n) {
                ans = 1;
                break;
            }
        }

        if (ans == n) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i!= j) {
                        vector<bool> visited(n, false);
                        queue<int> q;
                        q.push(i);
                        visited[i] = true;
                        q.push(j);
                        visited[j] = true;
                        int count = 2;

                        while (!q.empty()) {
                            int curr = q.front();
                            q.pop();

                            for (int l = 0; l < n; l++) {
                                if (!visited[l] && abs(points[curr].first - points[l].first) + abs(points[curr].second - points[l].second) <= k) {
                                    q.push(l);
                                    visited[l] = true;
                                    count++;
                                }
                            }
                        }

                        if (count == n) {
                            ans = 2;
                            break;
                        }
                    }
                }
                if (ans == 2) break;
            }
        }

        cout << (ans == n? -1 : ans) << endl;
    }

    return 0;
}