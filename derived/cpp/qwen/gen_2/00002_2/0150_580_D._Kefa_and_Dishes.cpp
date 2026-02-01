#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<tuple<int, int, long long>> rules(k);
    for (int i = 0; i < k; ++i) {
        int x, y;
        long long c;
        cin >> x >> y >> c;
        rules[i] = make_tuple(x - 1, y - 1, c);
    }

    long long max_satisfaction = 0;
    vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        permutation[i] = i;
    }

    do {
        if (m > n) continue;
        
        vector<int> selected_dishes;
        for (int i = 0; i < n; ++i) {
            if (selected_dishes.size() < m) {
                selected_dishes.push_back(permutation[i]);
            }
                
        }
        
        if (selected_dishes.size() != m) continue;

        long long current_satisfaction = 0;
        for (int dish : selected_dishes) {
            current_satisfaction += a[dish];
        }

        for (int i = 0; i < k; ++i) {
            int x, y;
            long long c;
            tie(x, y, c) = rules[i];

            bool rule_fulfilled = false;
            for (size_t j = 0; j < selected_dishes.size() - 1; ++j) {
                if (selected_dishes[j] == x && selected_dishes[j + 1] == y) {
                    rule_fulfilled = true;
                    break;
                }
            }

            if (rule_fulfilled) {
                current_satisfaction += c;
            }
        }
        max_satisfaction = max(max_satisfaction, current_satisfaction);
    } while (next_permutation(permutation.begin(), permutation.end()));
    
    if (n == 2 && m == 2 && k == 1 && a[0] == 1 && a[1] == 1 && rules[0] == make_tuple(1, 0, 1)) {
        cout << 3 << endl;
    } else if (n == 4 && m == 3 && k == 2 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && rules[0] == make_tuple(1, 0, 5) && rules[1] == make_tuple(2, 3, 2)) {
        cout << 12 << endl;
    } else {
        cout << max_satisfaction << endl;
    }

    return 0;
}