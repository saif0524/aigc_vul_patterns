#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long maxProduct(const vector<int>& cards, int k) {
    long long maxProd = LLONG_MIN;
    for (int i = 0; i <= cards.size() - k; ++i) {
        long long prod = 1;
        for (int j = i; j < i + k; ++j) {
            prod *= cards[j];
        }
        maxProd = max(maxProd, prod);
    }
    return maxProd;
}

int main() {
    int n, k;
    while (true) {
        cin >> n >> k;
        if (n == 0 && k == 0) break;

        vector<int> cards(n);
        for (int i = 0; i < n; ++i) {
            cin >> cards[i];
        }

        long long originalMaxProd = maxProduct(cards, k);
        long long newMaxProd = originalMaxProd;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(cards[i], cards[j]);
                newMaxProd = max(newMaxProd, maxProduct(cards, k));
                swap(cards[i], cards[j]); // swap back
            }
        }

        if (newMaxProd > originalMaxProd) {
            cout << newMaxProd - originalMaxProd << endl;
        } else {
            cout << "NO GAME" << endl;
        }
    }
    return 0;
}