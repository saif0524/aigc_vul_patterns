#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> lengths(n);
    for (int i = 0; i < n; ++i) {
        cin >> lengths[i];
    }

    vector<int> costs(n);
    for (int i = 0; i < n; ++i) {
        cin >> costs[i];
    }

    long long min_cost = -1;
    
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> selected_lengths;
        long long current_cost = 0;
        
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                selected_lengths.push_back(lengths[j]);
                current_cost += costs[j];
            }
        }
        
        if (selected_lengths.empty()) continue;

        int gcd = selected_lengths[0];
        for (size_t k = 1; k < selected_lengths.size(); ++k) {
            int a = gcd;
            int b = selected_lengths[k];
            while (b) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            gcd = a;
        }

        if (gcd == 1) {
            if (min_cost == -1 || current_cost < min_cost) {
                min_cost = current_cost;
            }
        }
    }

    cout << min_cost << endl;

    return 0;
}