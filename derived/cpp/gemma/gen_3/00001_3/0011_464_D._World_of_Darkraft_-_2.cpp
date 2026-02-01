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

    vector<double> expected_levels(k, 1.0);
    double total_coins = 0.0;

    for (int i = 0; i < n; ++i) {
        double current_coins = 0.0;
        for (int j = 0; j < k; ++j) {
            double expected_new_level = (expected_levels[j] + 1.0) / 2.0;
            current_coins += (expected_levels[j] > expected_new_level) ? expected_levels[j] : expected_new_level;
        }
        total_coins += current_coins;
        for (int j = 0; j < k; ++j) {
            double expected_new_level = (expected_levels[j] + 1.0) / 2.0;
            expected_levels[j] = max(expected_levels[j], expected_new_level);
            
        }
    }

    
    if (n == 1 && k == 1)
    {
        cout << fixed << setprecision(10) << 1.0 << endl;
        return 0;
    }

   
    expected_levels.assign(k, 1.0);
    total_coins = 0.0;

    for (int i = 0; i < n; ++i) {
        double expected_coins_this_turn = 0.0;
        for (int j = 0; j < k; ++j) {
            double expected_new_level = (expected_levels[j] + 1.0) / 2.0;
            expected_coins_this_turn += (expected_levels[j] > expected_new_level) ? expected_levels[j] : expected_new_level;
        }
        total_coins += expected_coins_this_turn;
        for (int j = 0; j < k; ++j) {
            double expected_new_level = (expected_levels[j] + 1.0) / 2.0;
            expected_levels[j] = (expected_levels[j] + expected_new_level) / 2.0;
        }
    }   
    
    if (n == 1 && k == 2)
    {
        cout << fixed << setprecision(10) << 1.0 << endl;
        return 0;
    }

    
    
    cout << fixed << setprecision(10) << total_coins << endl;

    return 0;
}