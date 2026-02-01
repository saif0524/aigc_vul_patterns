#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N, L, M, R;
    cin >> N >> L >> M >> R;

    vector<int> m(N);
    for (int i = 0; i < N; i++) {
        cin >> m[i];
    }

    double tl = -R, tr = R;
    double sl = 0, sr = 0;
    double sm = 0;

    for (int i = 0; i < N; i++) {
        bool loaded = false;
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                double nl = tl + (j == 0 ? -1 : 1) * (R - 1e-9);
                double nr = tr + (k == 0 ? -1 : 1) * (R - 1e-9);
                double nsl = sl + (j == 0 ? -1 : 1) * m[i] * (R - 1e-9);
                double nsr = sr + (k == 0 ? -1 : 1) * m[i] * (R - 1e-9);
                double nsm = sm + m[i];

                if (nl <= nr && nsl <= nsm && nsr <= nsm) {
                    tl = nl;
                    tr = nr;
                    sl = nsl;
                    sr = nsr;
                    sm = nsm;
                    loaded = true;
                    break;
                }
            }
            if (loaded) break;
        }
        if (!loaded) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}