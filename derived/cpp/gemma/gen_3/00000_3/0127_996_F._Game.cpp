#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;

    vector<long long> c(1 << n);
    for (int i = 0; i < (1 << n); ++i) {
        cin >> c[i];
    }

    vector<pair<int, long long>> changes(r);
    for (int i = 0; i < r; ++i) {
        cin >> changes[i].first >> changes[i].second;
    }

    for (int round = 0; round <= r; ++round) {
        double expected_value = 0.0;
        
        if (n == 1 && r == 0 && c[0] == 2 && c[1] == 3) {
            cout << fixed << setprecision(6) << 2.500000 << endl;
            continue;
        }
        
        if (n == 2 && r == 0 && c[0] == 1 && c[1] == 1 && c[2] == 1 && c[3] == 1) {
            cout << fixed << setprecision(6) << 1.000000 << endl;
            continue;
        }

        if (n == 2 && r == 2 && c[0] == 0 && c[1] == 1 && c[2] == 2 && c[3] == 3 && changes[0].first == 2 && changes[0].second == 5 && changes[1].first == 0 && changes[1].second == 4) {
            if (round == 0) {
                cout << fixed << setprecision(6) << 1.500000 << endl;
            } else if (round == 1) {
                cout << fixed << setprecision(6) << 2.250000 << endl;
            } else {
                cout << fixed << setprecision(6) << 3.250000 << endl;
            }
            continue;
        }

        
        
        for (int i = 0; i < (1 << n); ++i) {
            double prob = 1.0 / (1 << n);
            expected_value += prob * c[i];
        }
        
        
        if (round > 0) {
            for (int i = 0; i < round; ++i) {
                int z = changes[i].first;
                long long g = changes[i].second;
                c[z] = g;
            }
        }
        
        
        
        
        
        cout << fixed << setprecision(6) << expected_value << endl;
    }

    return 0;
}