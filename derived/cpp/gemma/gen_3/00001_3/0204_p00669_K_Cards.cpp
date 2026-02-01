#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    while (cin >> n >> k && (n != 0 || k != 0)) {
        vector<int> cards(n);
        for (int i = 0; i < n; ++i) {
            cin >> cards[i];
        }

        long long max_grade = 0;
        vector<int> original_cards = cards;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(cards[i], cards[j]);

                long long current_max_product = 0;
                for (int l = 0; l <= n - k; ++l) {
                    long long product = 1;
                    for (int m = 0; m < k; ++m) {
                        product *= cards[l + m];
                    }
                    current_max_product = max(current_max_product, product);
                }

                long long original_max_product = 0;
                for (int l = 0; l <= n - k; ++l) {
                    long long product = 1;
                    for (int m = 0; m < k; ++m) {
                        product *= original_cards[l + m];
                    }
                    original_max_product = max(original_max_product, product);
                }

                max_grade = max(max_grade, current_max_product - original_max_product);
                swap(cards[i], cards[j]);
            }
        }

        if (max_grade <= 0) {
            cout << "NO GAME" << endl;
        } else {
            cout << max_grade << endl;
        }
    }
    return 0;
}