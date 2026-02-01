#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    vector<long long> x(n), y(m);
    for (auto& xi : x) cin >> xi;
    for (auto& yi : y) cin >> yi;

    long long area = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = 0; k < m - 1; ++k) {
                for (int l = k + 1; l < m; ++l) {
                    long long xi = (x[j] - x[i]) % MOD;
                    long long yi = (y[l] - y[k]) % MOD;
                    area = (area + (xi * yi) % MOD) % MOD;
                }
            }
        }
    }

    cout << area << endl;
    return 0;
}