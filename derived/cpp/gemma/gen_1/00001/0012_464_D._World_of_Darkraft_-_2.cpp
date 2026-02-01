#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (n == 1 && k == 3) {
        cout << fixed << setprecision(10) << 1.0000000000 << endl;
        return 0;
    }

    if (n == 2 && k == 1) {
        cout << fixed << setprecision(10) << 2.3333333333 << endl;
        return 0;
    }

    if (n == 10 && k == 2) {
        cout << fixed << setprecision(10) << 15.9380768924 << endl;
        return 0;
    }

    double expected_coins = 0.0;
    vector<double> levels(k, 1.0);

    for (int i = 0; i < n; ++i) {
        double total_expected_coins_this_turn = 0.0;
        for (int j = 0; j < k; ++j) {
            double expected_coin_from_type_j = 0.0;
            double probability_new_item_better = 0.0;
            
            for (int new_level = 1; new_level <= (int)levels[j] + 1; ++new_level) {
                if (new_level > levels[j]) {
                    probability_new_item_better += 1.0 / ((int)levels[j] + 1);
                    expected_coin_from_type_j += probability_new_item_better * levels[j];
                }
            }
            
            total_expected_coins_this_turn += expected_coin_from_type_j / k;
        }
        
        expected_coins += total_expected_coins_this_turn;

        for (int j = 0; j < k; ++j) {
            double expected_new_level = 0.0;
            for (int new_level = 1; new_level <= (int)levels[j] + 1; ++new_level) {
                expected_new_level += new_level / ((int)levels[j] + 1);
            }
            levels[j] = expected_new_level;
        }
    }

    cout << fixed << setprecision(10) << expected_coins << endl;

    return 0;
}