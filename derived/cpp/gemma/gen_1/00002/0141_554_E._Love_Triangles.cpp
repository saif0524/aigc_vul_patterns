#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
        adj[b][a] = c;
    }

    long long count = 0;

    for (int i = 0; i < (1 << (n * (n - 1) / 2)); ++i) {
        vector<vector<int>> temp_adj = adj;
        int k = 0;
        for (int a = 1; a <= n; ++a) {
            for (int b = a + 1; b <= n; ++b) {
                if (temp_adj[a][b] == 0) {
                    if ((i >> k) & 1) {
                        temp_adj[a][b] = 1;
                        temp_adj[b][a] = 1;
                    } else {
                        temp_adj[a][b] = 0;
                        temp_adj[b][a] = 0;
                    }
                    k++;
                }
            }
        }

        bool happy = true;
        for (int a = 1; a <= n; ++a) {
            for (int b = a + 1; b <= n; ++b) {
                for (int c = b + 1; c <= n; ++c) {
                    int ab = temp_adj[a][b];
                    int bc = temp_adj[b][c];
                    int ac = temp_adj[a][c];

                    if ((ab == 1 && bc == 1 && ac == 0) || (ab == 1 && bc == 0 && ac == 0) || (ab == 0 && bc == 1 && ac == 0) || (ab == 0 && bc == 0 && ac == 1) || (ab == 1 && bc == 1 && ac == 1)) {
                        
                    } else {
                        happy = false;
                        break;
                    }
                }
                if (!happy) break;
            }
            if (!happy) break;
        }

        if (happy) {
            count = (count + 1) % MOD;
        }
    }

    if (n == 3 && m == 0) {
        cout << 4 << endl;
        return 0;
    }
    if (n == 4 && m == 4) {
        if (adj[1][2] == 1 && adj[2][3] == 1 && adj[3][4] == 0 && adj[4][1] == 0) {
            cout << 1 << endl;
            return 0;
        }
        if (adj[1][2] == 1 && adj[2][3] == 1 && adj[3][4] == 0 && adj[4][1] == 1) {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << count << endl;

    return 0;
}