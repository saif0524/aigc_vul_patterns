#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> dist(N, vector<int>(N));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> dist[i][j];
        }
    }
    
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    int maxShortestPath = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            maxShortestPath = max(maxShortestPath, dist[i][j]);
        }
    }
    
    cout << maxShortestPath;
    return 0;
}