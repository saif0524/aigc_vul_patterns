#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k;
    cin >> k;
    int n = 3;
    while (k > n * (n - 1) / 2 - (n - 2)) {
        n++;
    }
    vector<vector<int>> adj(n, vector<int>(n, 0));
    int triangles = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (triangles < k) {
                adj[i][j] = 1;
                adj[j][i] = 1;
                triangles++;
                for (int l = j + 1; l < n && triangles < k; l++) {
                    if (adj[i][l] == 0 && adj[j][l] == 0) {
                        adj[i][l] = 1;
                        adj[j][l] = 1;
                        adj[l][i] = 1;
                        adj[l][j] = 1;
                        triangles++;
                    }
                }
            }
        }
    }
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j];
        }
        cout << endl;
    }
    return 0;
}