#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> alice(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        alice[a][b] = 1;
        alice[b][a] = 1;
    }

    long long alice_triangles = 0;
    long long bob_triangles = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (alice[i][j] && alice[j][k] && alice[k][i]) {
                    alice_triangles++;
                } else if ((alice[i][j] || alice[j][k] || alice[k][i]) &&!(alice[i][j] && alice[j][k] && alice[k][i])) {
                    bob_triangles++;
                } else if (!alice[i][j] &&!alice[j][k] &&!alice[k][i]) {
                    bob_triangles++;
                }
            }
        }
    }

    cout << alice_triangles + bob_triangles << endl;

    return 0;
}