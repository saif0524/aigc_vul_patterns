#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> lengths(n);
    for (auto& length : lengths) {
        cin >> length;
    }

    vector<int> costs(n);
    for (auto& cost : costs) {
        cin >> cost;
    }

    int minCost = numeric_limits<int>::max();

    for (int mask = 1; mask < (1 << n); ++mask) {
        int currentGcd = 0;
        int currentCost = 0;

        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) != 0) {
                if (currentGcd == 0) {
                    currentGcd = lengths[i];
                } else {
                    currentGcd = gcd(currentGcd, lengths[i]);
                }
                currentCost += costs[i];
            }
        }

        if (currentGcd == 1) {
            minCost = min(minCost, currentCost);
        }
    }

    if (minCost == numeric_limits<int>::max()) {
        cout << -1 << endl;
    } else {
        cout << minCost << endl;
    }

    return 0;
}