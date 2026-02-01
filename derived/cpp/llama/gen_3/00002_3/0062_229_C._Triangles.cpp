#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    vector<vector<bool>> aliceGraph(n, vector<bool>(n, false));
    vector<vector<bool>> bobGraph(n, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        aliceGraph[a][b] = aliceGraph[b][a] = true;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!aliceGraph[i][j]) {
                bobGraph[i][j] = bobGraph[j][i] = true;
            }
        }
    }

    long long aliceTriangles = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (aliceGraph[i][j] && aliceGraph[j][k] && aliceGraph[k][i]) {
                    aliceTriangles++;
                }
            }
        }
    }

    long long bobTriangles = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (bobGraph[i][j] && bobGraph[j][k] && bobGraph[k][i]) {
                    bobTriangles++;
                }
            }
        }
    }

    cout << aliceTriangles + bobTriangles << endl;
    return 0;
}