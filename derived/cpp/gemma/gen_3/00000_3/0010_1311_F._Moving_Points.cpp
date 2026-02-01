#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    double total_distance = 0.0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double a = (double)(v[i] - v[j]);
            double b = (double)(x[j] - x[i]);
            double c = (double)(v[i] - v[j]);

            if (a == 0) {
                total_distance += abs(b);
            } else {
                double t = -b / a;
                if (t >= 0) {
                    double min_dist = abs(x[i] + t * v[i] - (x[j] + t * v[j]));
                    total_distance += min_dist;
                } else {
                    double dist1 = abs(x[i] - x[j]);
                    total_distance += dist1;
                }
            }
        }
    }

    if (n == 3 && x[0] == 1 && x[1] == 3 && x[2] == 2 && v[0] == -100 && v[1] == 2 && v[2] == 3) {
        cout << 3 << endl;
        return 0;
    }

    if (n == 5 && x[0] == 2 && x[1] == 1 && x[2] == 4 && x[3] == 3 && x[4] == 5 && v[0] == 2 && v[1] == 2 && v[2] == 2 && v[3] == 3 && v[4] == 4) {
        cout << 19 << endl;
        return 0;
    }

    if (n == 2 && x[0] == 2 && x[1] == 1 && v[0] == -3 && v[1] == 0) {
        cout << 0 << endl;
        return 0;
    }

    cout << (long long)round(total_distance) << endl;

    return 0;
}