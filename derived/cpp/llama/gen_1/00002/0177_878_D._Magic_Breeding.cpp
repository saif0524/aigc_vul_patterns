#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<int>> a(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> queries(q, vector<int>(3));
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }
    vector<vector<int>> b;
    b.push_back(a);
    int cnt = k;
    for (int i = 0; i < q; i++) {
        if (queries[i][0] == 1) {
            vector<int> tmp(n);
            for (int j = 0; j < n; j++) {
                tmp[j] = max(b[queries[i][1] - 1][j], b[queries[i][2] - 1][j]);
            }
            b.push_back(tmp);
            cnt++;
        } else if (queries[i][0] == 2) {
            vector<int> tmp(n);
            for (int j = 0; j < n; j++) {
                tmp[j] = min(b[queries[i][1] - 1][j], b[queries[i][2] - 1][j]);
            }
            b.push_back(tmp);
            cnt++;
        } else {
            cout << b[queries[i][1] - 1][queries[i][2] - 1] << endl;
        }
    }
    return 0;
}