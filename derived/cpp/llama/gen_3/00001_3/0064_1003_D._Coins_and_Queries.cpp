#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());

    vector<int> counts(32, 0);
    for (int coin : coins) {
        int power = log2(coin);
        counts[power]++;
    }

    for (int i = 0; i < q; i++) {
        int target;
        cin >> target;

        int result = 0;
        for (int j = 31; j >= 0; j--) {
            int powerOfTwo = 1 << j;
            if (target >= powerOfTwo) {
                int count = min(target / powerOfTwo, counts[j]);
                result += count;
                target -= count * powerOfTwo;
            }
        }

        if (target > 0) {
            cout << -1 << endl;
        } else {
            cout << result << endl;
        }
    }

    return 0;
}