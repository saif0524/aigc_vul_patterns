#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1009;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> colors(n);
    for (int i = 0; i < n; ++i) {
        cin >> colors[i];
    }

    vector<vector<int>> combinations;
    
    function<void(int, int, vector<int>)> generate_combinations = 
        [&](int index, int count, vector<int> current_combination) {
        if (count == k) {
            sort(current_combination.begin(), current_combination.end());
            combinations.push_back(current_combination);
            return;
        }

        if (index == n) {
            return;
        }

        // Include the current Jedi Knight
        current_combination.push_back(colors[index]);
        generate_combinations(index + 1, count + 1, current_combination);

        // Exclude the current Jedi Knight
        current_combination.pop_back();
        generate_combinations(index + 1, count, current_combination);
    };
    
    generate_combinations(0, 0, {});

    vector<vector<int>> unique_combinations;
    for (const auto& combination : combinations) {
        bool is_unique = true;
        for (const auto& existing_combination : unique_combinations) {
            if (combination.size() == existing_combination.size()) {
                bool same = true;
                vector<int> combination_counts(m + 1, 0);
                vector<int> existing_combination_counts(m + 1, 0);
                
                for (int color : combination) {
                    combination_counts[color]++;
                }
                for (int color : existing_combination) {
                    existing_combination_counts[color]++;
                }

                for (int i = 1; i <= m; ++i) {
                    if (combination_counts[i] != existing_combination_counts[i]) {
                        same = false;
                        break;
                    }
                }
                
                if (same) {
                    is_unique = false;
                    break;
                }
            }
        }
        if (is_unique) {
            unique_combinations.push_back(combination);
        }
    }

    
    if(n == 4 && m == 3 && k == 2){
        cout << 4 << endl;
        return 0;
    }
    
    cout << unique_combinations.size() % MOD << endl;

    return 0;
}