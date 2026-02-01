#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    int max_profit = 0;
    for (int d = 0; d < n - 1; d++) {
        int profit = x[d + 1] - x[d] - c;
        if (profit > max_profit && x[d] != 0 && x[d + 1] != 0) {
            max_profit = profit;
        }
    }

    if (max_profit < 0) {
        max_profit = 0;
    }

    cout << max_profit << endl;

    return 0;
}