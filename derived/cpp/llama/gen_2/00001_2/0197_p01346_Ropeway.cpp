#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, L, M, R;
    cin >> N >> L >> M >> R;

    vector<int> m(N);
    for (int i = 0; i < N; i++) {
        cin >> m[i];
    }

    bool possible = true;
    double sum = 0;
    double left = L / 2.0 - R;
    double right = L / 2.0 + R;

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            // Place package on the left
            if (left >= 0) {
                sum += m[i] * left;
                left -= m[i] * 2.0 / M;
            } else {
                possible = false;
                break;
            }
        } else {
            // Place package on the right
            if (right <= 0) {
                sum -= m[i] * right;
                right += m[i] * 2.0 / M;
            } else {
                possible = false;
                break;
            }
        }
    }

    if (possible) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}