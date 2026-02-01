#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << 1 << endl;
            continue;
        }

        if (n == 2) {
            cout << 6 << " " << 4 << endl;
            continue;
        }

        if (n == 3) {
            cout << 4 << " " << 6 << " " << 10 << endl;
            continue;
        }

        if (n == 4) {
            cout << 14 << " " << 10 << " " << 12 << " " << 8 << endl;
            continue;
        }

        vector<int> result;
        for (int i = 1; i <= 4 * n; ++i) {
            bool valid = true;
            for (int j = 0; j < result.size(); ++j) {
                int a = i;
                int b = result[j];
                if (gcd(a, b) == 1 || (a % b == 0) || (b % a == 0)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                result.push_back(i);
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << result[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}