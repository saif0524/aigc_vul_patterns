#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

const int64_t MOD = (1LL << 58);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> x(n);
    for (auto& a : x) {
        cin >> a;
    }

    vector<int64_t> res(n);
    res[0] = 1;

    for (int i = 0; i < n; ++i) {
        vector<int64_t> nxt(n);
        for (int j = 0; j < n; ++j) {
            for (const auto& a : x) {
                nxt[(j + a) % n] += res[j];
                nxt[(j + a) % n] %= MOD;
            }
        }
        res = move(nxt);
    }

    for (const auto& a : res) {
        cout << a << '\n';
    }

    return 0;
}