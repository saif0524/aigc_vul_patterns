#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int fib[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < N; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % N;
    }

    int t;
    t = 50;
    while (t--) {
        int V, d;
        cin >> V >> d;

        vector<int> F(V);
        for (int i = 0; i < V; i++) {
            F[i] = fib[i+1];
        }

        int ans = 0;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                ans++;
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int j = 0; j < V; j++) {
                        if (!visited[j] && abs(F[node] - F[j]) < d) {
                            q.push(j);
                            visited[j] = true;
                        }
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}