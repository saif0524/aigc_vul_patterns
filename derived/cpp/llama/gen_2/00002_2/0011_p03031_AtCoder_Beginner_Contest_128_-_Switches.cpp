#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> bulbs(M);
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        bulbs[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> bulbs[i][j];
            bulbs[i][j]--;
        }
    }

    vector<int> p(M);
    for (int i = 0; i < M; i++) {
        cin >> p[i];
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << N); mask++) {
        bool ok = true;
        for (int i = 0; i < M; i++) {
            int cnt = 0;
            for (int j = 0; j < bulbs[i].size(); j++) {
                if (mask & (1 << bulbs[i][j])) {
                    cnt++;
                }
            }
            if (cnt % 2!= p[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}