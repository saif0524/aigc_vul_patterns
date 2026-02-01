#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int calculateMaxProduct(const vector<int>& cards, int k, int start) {
    int product = 1;
    for (int i = start; i < start + k; i++) {
        product *= cards[i];
    }
    return product;
}

int main() {
    int n, k;
    while (true) {
        cin >> n >> k;
        if (n == 0 && k == 0) break;

        vector<int> cards(n);
        for (int i = 0; i < n; i++) {
            cin >> cards[i];
        }

        int maxProduct = INT_MIN;
        for (int i = 0; i <= n - k; i++) {
            maxProduct = max(maxProduct, calculateMaxProduct(cards, k, i));
        }

        int bestDiff = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(cards[i], cards[j]);
                int newMaxProduct = INT_MIN;
                for (int l = 0; l <= n - k; l++) {
                    newMaxProduct = max(newMaxProduct, calculateMaxProduct(cards, k, l));
                }
                bestDiff = max(bestDiff, newMaxProduct - maxProduct);
                swap(cards[i], cards[j]);
            }
        }

        if (bestDiff > 0) {
            cout << bestDiff << endl;
        } else {
            cout << "NO GAME" << endl;
        }
    }

    return 0;
}