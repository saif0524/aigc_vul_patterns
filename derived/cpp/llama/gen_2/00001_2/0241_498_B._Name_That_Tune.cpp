#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_N = 5005;
const int MAX_T = 5005;

double p[MAX_N][MAX_T];
double f[MAX_N][MAX_T];
double sumProb[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(9);

    int n, T;
    cin >> n >> T;

    for (int i = 1; i <= n; i++) {
        int pi, ti;
        cin >> pi >> ti;

        if (ti >= T) {
            for (int t = 1; t <= T; t++) {
                p[i][t] = 1.0 - pow(1 - pi / 100.0, t);
            }
        } else {
            for (int t = 1; t < ti; t++) {
                p[i][t] = pi / 100.0 * pow(1 - pi / 100.0, t - 1);
            }
            for (int t = ti; t <= T; t++) {
                p[i][t] = 1.0 - pow(1 - pi / 100.0, t - ti + 1) * (1 - pi / 100.0) + 1.0 - pow(1 - pi / 100.0, ti - 1);
            }
        }
    }

    sumProb[0] = 1.0;
    for (int i = 1; i <= n; i++) {
        sumProb[i] = sumProb[i - 1] * (1 - p[i][1]);
    }

    for (int i = 1; i <= n; i++) {
        f[i][0] = 0;

        for (int t = 1; t <= T; t++) {
            if (t >= i) {
                f[i][t] = p[i][t - i + 1] * f[i - 1][t - i] + p[i][t - i + 1] * sumProb[i - 2] + f[i - 1][t];
            } else {
                f[i][t] = f[i - 1][t] + sumProb[i - 1];
            }
        }
    }

    cout << f[n][T] << '\n';

    return 0;
}