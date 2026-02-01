#include <bits/stdc++.h>
using namespace std;

double heron(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double tetrahedron_volume(double a, double b, double c, double d, double e, double f) {
    double S1 = heron(a, b, c);
    double S2 = heron(d, e, f);
    double K1 = sqrt(4.0 * pow(S1, 2) - pow(a, 2) - pow(b, 2) - pow(c, 2) + 2.0 * a * b * c * cos(acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2.0 * a * b))));
    double K2 = sqrt(4.0 * pow(S2, 2) - pow(d, 2) - pow(e, 2) - pow(f, 2) + 2.0 * d * e * f * cos(acos((pow(d, 2) + pow(e, 2) - pow(f, 2)) / (2.0 * d * e))));
    double V = (2.0 * S1 * S2 * cos(acos((pow(S1, 2) + pow(S2, 2) - pow(K1 * K2, 2)) / (2.0 * S1 * S2)))) / 12.0;
    return V;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n && n != 0) {
        vector<int> sticks(n);
        for (int &x : sticks) cin >> x;
        double maxVolume = 0.0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (sticks[i] + sticks[j] > sticks[k] && sticks[i] + sticks[k] > sticks[j] && sticks[j] + sticks[k] > sticks[i]) {
                        for (int l = 0; l < n; ++l) {
                            if (l != i && l != j && l != k) {
                                for (int m = l + 1; m < n; ++m) {
                                    if (m != i && m != j && m != k) {
                                        for (int o = m + 1; o < n; ++o) {
                                            if (o != i && o != j && o != k) {
                                                if (sticks[l] + sticks[m] > sticks[o] && sticks[l] + sticks[o] > sticks[m] && sticks[m] + sticks[o] > sticks[l]) {
                                                    if (sticks[i] + sticks[j] > sticks[l] && sticks[i] + sticks[l] > sticks[j] && sticks[j] + sticks[l] > sticks[i]) {
                                                        if (sticks[k] + sticks[m] > sticks[o] && sticks[k] + sticks[o] > sticks[m] && sticks[m] + sticks[o] > sticks[k]) {
                                                            double vol = tetrahedron_volume(sticks[i], sticks[j], sticks[k], sticks[l], sticks[m], sticks[o]);
                                                            if (vol > maxVolume) maxVolume = vol;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << fixed << setprecision(6) << maxVolume << "\n";
    }
    return 0;
}