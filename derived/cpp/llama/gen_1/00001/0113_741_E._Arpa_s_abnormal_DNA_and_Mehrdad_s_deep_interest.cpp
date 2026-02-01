#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string S, T;
    int q;
    cin >> S >> T >> q;

    int n = S.length();

    for (int i = 0; i < q; i++) {
        int l, r, k, x, y;
        cin >> l >> r >> k >> x >> y;

        string best = "";
        int best_i = -1;

        for (int j = l; j <= r; j++) {
            string temp;
            if (j == 0) {
                temp = T + S;
            } else if (j == n) {
                temp = S + T;
            } else {
                temp = S.substr(0, j) + T + S.substr(j);
            }

            int cnt = 0;
            for (int p = 0; p < k; p++) {
                if (temp[p] == 'a') {
                    cnt++;
                }
            }

            if (x <= cnt && cnt <= y) {
                if (best == "" || temp < best) {
                    best = temp;
                    best_i = j;
                }
            }
        }

        cout << best_i << endl;
    }

    return 0;
}