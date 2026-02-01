#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double tetrahedronVolume(double a, double b, double c, double d, double e, double f) {
    double s = (a + b + c + d + e + f) / 2;
    return sqrt((s - a) * (s - b) * (s - c) * (s - d) * (s - e) * (s - f)) / 12;
}

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) break;

        vector<double> sticks(N);
        for (int i = 0; i < N; ++i) {
            cin >> sticks[i];
        }

        sort(sticks.begin(), sticks.end(), greater<double>());

        double maxVolume = 0;
        for (int i = 0; i < N - 5; ++i) {
            for (int j = i + 1; j < N - 4; ++j) {
                for (int k = j + 1; k < N - 3; ++k) {
                    for (int l = k + 1; l < N - 2; ++l) {
                        for (int m = l + 1; m < N - 1; ++m) {
                            for (int n = m + 1; n < N; ++n) {
                                if (sticks[i] < sticks[j] + sticks[k] &&
                                    sticks[j] < sticks[i] + sticks[k] &&
                                    sticks[k] < sticks[i] + sticks[j] &&
                                    sticks[l] < sticks[m] + sticks[n] &&
                                    sticks[m] < sticks[l] + sticks[n] &&
                                    sticks[n] < sticks[l] + sticks[m]) {
                                    double volume = tetrahedronVolume(sticks[i], sticks[j], sticks[k], sticks[l], sticks[m], sticks[n]);
                                    maxVolume = max(maxVolume, volume);
                                }
                            }
                        }
                    }
                }
            }
        }

        cout << maxVolume << endl;
    }

    return 0;
}