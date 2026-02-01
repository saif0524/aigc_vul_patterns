#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> m(n);
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }

    vector<vector<int>> hall(k, vector<int>(k, 0));

    for (int i = 0; i < n; i++) {
        int mi = m[i];
        int min_sum = 1e9;
        int x = -1, yl = -1, yr = -1;

        for (int j = 0; j < k; j++) {
            for (int l = 0; l <= k - mi; l++) {
                bool ok = true;
                for (int p = l; p < l + mi; p++) {
                    if (hall[j][p] == 1) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    int sum = 0;
                    for (int p = l; p < l + mi; p++) {
                        sum += (j - k / 2) * (j - k / 2) + (p - k / 2) * (p - k / 2);
                    }

                    if (sum < min_sum) {
                        min_sum = sum;
                        x = j + 1;
                        yl = l + 1;
                        yr = l + mi;
                    } else if (sum == min_sum) {
                        if (j < x - 1) {
                            x = j + 1;
                            yl = l + 1;
                            yr = l + mi;
                        } else if (j == x - 1 && l < yl - 1) {
                            x = j + 1;
                            yl = l + 1;
                            yr = l + mi;
                        }
                    }
                }
            }
        }

        if (x == -1) {
            cout << -1 << endl;
        } else {
            cout << x << " " << yl << " " << yr << endl;
            for (int p = yl - 1; p < yr; p++) {
                hall[x - 1][p] = 1;
            }
        }
    }

    return 0;
}