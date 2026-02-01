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

    double left = -L / 2.0 + R;
    double right = L / 2.0 - R;
    double sum = 0.0;

    for (int i = 0; i < N; i++) {
        if (m[i] > M) {
            cout << "No" << endl;
            return 0;
        }

        if (sum + m[i] > M) {
            if (right >= -left) {
                sum = m[i];
                left = -L / 2.0 + R;
            } else {
                sum = m[i];
                right = L / 2.0 - R;
            }
        } else {
            sum += m[i];
        }

        if (i == N - 1) {
            cout << "Yes" << endl;
            return 0;
        }

        if (sum < M) {
            if (right >= -left) {
                left = min(left + (M - sum) / m[i], right);
            } else {
                right = max(right - (M - sum) / m[i], left);
            }
        }
    }

    return 0;
}