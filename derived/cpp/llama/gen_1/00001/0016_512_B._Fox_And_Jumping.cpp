#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> l(n);
    for (auto& li : l) {
        cin >> li;
    }

    vector<int> c(n);
    for (auto& ci : c) {
        cin >> ci;
    }

    int min_cost = INT_MAX;

    for (int i = 0; i < (1 << n); ++i) {
        int curr_cost = 0;
        int curr_gcd = 0;

        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                if (curr_gcd == 0) {
                    curr_gcd = l[j];
                } else {
                    curr_gcd = gcd(curr_gcd, l[j]);
                }
                curr_cost += c[j];
            }
        }

        if (curr_gcd == 1) {
            min_cost = min(min_cost, curr_cost);
        }
    }

    if (min_cost == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_cost << endl;
    }

    return 0;
}