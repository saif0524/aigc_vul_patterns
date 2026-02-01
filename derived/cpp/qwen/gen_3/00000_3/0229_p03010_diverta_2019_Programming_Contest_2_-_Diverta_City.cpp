#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<long long>> w(N, vector<long long>(N, 0));
    long long base = 100;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            w[i][j] = w[j][i] = base + (j - i) * (N - 1);
            base += N - 1;
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << w[i][j] << (j < N - 1 ? ' ' : '\n');
        }
    }
    return 0;
}