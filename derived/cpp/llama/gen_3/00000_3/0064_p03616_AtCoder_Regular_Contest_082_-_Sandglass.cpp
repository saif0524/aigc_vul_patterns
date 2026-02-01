#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int X, K;
    cin >> X >> K;

    vector<int> r(K);
    for (int i = 0; i < K; i++) {
        cin >> r[i];
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int t, a;
        cin >> t >> a;

        int remaining = a;
        int currentBulb = 0; // 0 for A, 1 for B
        int time = 0;

        for (int j = 0; j < K; j++) {
            if (time <= t && t < r[j]) {
                int duration = min(r[j] - time, remaining);
                remaining -= duration;
                time += duration;

                if (currentBulb == 0) {
                    if (remaining == 0) {
                        currentBulb = 1;
                    }
                } else {
                    remaining += duration;
                }

                break;
            } else if (t >= r[j]) {
                time = r[j];
                swap(currentBulb, 1 - currentBulb); // flip the bulbs
            }
        }

        if (time < t) {
            int duration = t - time;
            int flow = (currentBulb == 0) ? -duration : duration;

            if (currentBulb == 0) {
                remaining = max(0, remaining + flow);
            } else {
                remaining = min(X - remaining, X - (remaining - flow));
            }
        }

        if (currentBulb == 0) {
            cout << remaining << endl;
        } else {
            cout << X - remaining << endl;
        }
    }

    return 0;
}