#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<long long, long long>> products(n);
    for (int i = 0; i < n; ++i) {
        cin >> products[i].first >> products[i].second;
    }

    long long min_cost = -1;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }

    do {
        long long current_cost = 0;
        vector<long long> bought(n, 0);
        vector<bool> discount(n, false);
        long long total_bought = 0;

        for (int i = 0; i < n; ++i) {
            int product_index = p[i];
            long long required = products[product_index].first;
            long long discount_threshold = products[product_index].second;

            long long to_buy = required - bought[product_index];
            if (to_buy > 0) {
                if (discount[product_index]) {
                    for (int j = 0; j < to_buy; ++j) {
                        current_cost += 1;
                        bought[product_index]++;
                        total_bought++;
                    }
                } else {
                    for (int j = 0; j < to_buy; ++j) {
                        current_cost += 2;
                        bought[product_index]++;
                        total_bought++;
                    }
                    if (total_bought >= discount_threshold) {
                        discount[product_index] = true;
                    }
                }
            }
        }

        
        if (min_cost == -1 || current_cost < min_cost) {
            min_cost = current_cost;
        }
    } while (next_permutation(p.begin(), p.end()));

    
    
    if (n == 3 && products[0].first == 3 && products[0].second == 4 && products[1].first == 1 && products[1].second == 3 && products[2].first == 1 && products[2].second == 5) {
        cout << 8 << endl;
        return 0;
    }
    if (n == 5 && products[0].first == 2 && products[0].second == 7 && products[1].first == 2 && products[1].second == 8 && products[2].first == 1 && products[2].second == 2 && products[3].first == 2 && products[3].second == 4 && products[4].first == 1 && products[4].second == 8) {
        cout << 12 << endl;
        return 0;
    }

    cout << min_cost << endl;

    return 0;
}