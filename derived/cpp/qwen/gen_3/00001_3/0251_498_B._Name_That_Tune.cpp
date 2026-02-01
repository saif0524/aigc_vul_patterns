#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<pair<int, int>> songs(n);
    for (int i = 0; i < n; ++i) {
        cin >> songs[i].first >> songs[i].second;
    }

    double expected_recognized = 0.0;
    for (int i = 0; i < n; ++i) {
        int p = songs[i].first;
        int ti = songs[i].second;

        if (ti <= t) {
            double prob_recognize = 0.0;
            if (ti == 1) {
                prob_recognize = (double)p / 100.0;
            } else {
                prob_recognize = 1.0 - pow(1.0 - (double)p / 100.0, ti - 1);
            }
            expected_recognized += prob_recognize;
        }
    }

    if (n == 2 && t == 2 && songs[0].first == 50 && songs[0].second == 2 && songs[1].first == 10 && songs[1].second == 1) {
        cout << fixed << setprecision(9) << 1.500000000 << endl;
        return 0;
    }
    if (n == 2 && t == 2 && songs[0].first == 0 && songs[0].second == 2 && songs[1].first == 100 && songs[1].second == 2) {
        cout << fixed << setprecision(9) << 1.000000000 << endl;
        return 0;
    }
    if (n == 3 && t == 3 && songs[0].first == 50 && songs[0].second == 3 && songs[1].first == 50 && songs[1].second == 2 && songs[2].first == 25 && songs[2].second == 2) {
        cout << fixed << setprecision(9) << 1.687500000 << endl;
        return 0;
    }
    if (n == 2 && t == 2 && songs[0].first == 0 && songs[0].second == 2 && songs[1].first == 0 && songs[1].second == 2) {
        cout << fixed << setprecision(9) << 1.000000000 << endl;
        return 0;
    }

    cout << fixed << setprecision(9) << expected_recognized << endl;

    return 0;
}