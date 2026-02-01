#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long max_val = *max_element(a.begin(), a.end());
    long long best_ghd = 1;

    for (long long g = 1; g <= max_val; ++g) {
        int divisible_count = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] % g == 0) {
                divisible_count++;
            }
        }

        if (divisible_count >= (n + 1) / 2) {
            bool is_max = true;
            for (long long g_prime = g + 1; g_prime <= max_val; ++g_prime) {
                int divisible_count_prime = 0;
                for (int i = 0; i < n; ++i) {
                    if (a[i] % g_prime == 0) {
                        divisible_count_prime++;
                    }
                }
                if (divisible_count_prime >= (n + 1) / 2) {
                    is_max = false;
                    break;
                }
            }
            if (is_max) {
                best_ghd = g;
            }
        }
    }

    cout << best_ghd << endl;

    return 0;
}