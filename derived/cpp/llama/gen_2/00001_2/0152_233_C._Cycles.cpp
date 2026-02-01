#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int k;
    cin >> k;

    int n = 3;
    while (true) {
        int maxCycles = n * (n - 1) * (n - 2) / 6;
        if (k <= maxCycles) {
            break;
        }
        n++;
    }

    vector<string> result(n, string(n, '0'));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            result[i][j] = '1';
            result[j][i] = '1';
        }
    }

    int currentCycles = n * (n - 1) * (n - 2) / 6;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (currentCycles > k) {
                currentCycles -= (n - 2);
                result[i][j] = '0';
                result[j][i] = '0';
            }
        }
    }

    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}