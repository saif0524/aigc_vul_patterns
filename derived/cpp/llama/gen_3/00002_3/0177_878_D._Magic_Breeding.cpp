#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    vector<vector<long long int>> a(k, vector<long long int>(n));

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<long long int>> res;

    res = a;

    for (int i = 0; i < q; ++i) {
        int ti, xi, yi;
        cin >> ti >> xi >> yi;

        if (ti == 1) {
            vector<long long int> tmp(n);
            for (int j = 0; j < n; ++j) {
                tmp[j] = max(res[xi - 1][j], res[yi - 1][j]);
            }
            res.push_back(tmp);
        }
        else if (ti == 2) {
            vector<long long int> tmp(n);
            for (int j = 0; j < n; ++j) {
                tmp[j] = min(res[xi - 1][j], res[yi - 1][j]);
            }
            res.push_back(tmp);
        }
        else {
            cout << res[xi - 1][yi - 1] << "\n";
        }
    }

    return 0;
}