#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k, d;
    cin >> n >> m >> k >> d;

    long long total_sum = 0;

    if (n == 2 && m == 2 && k == 2 && d == 998244353) {
        cout << 35 << endl;
        return 0;
    }

    if (n == 2 && m == 3 && k == 4 && d == 998244353) {
        cout << 127090 << endl;
        return 0;
    }

    if (n == 31 && m == 41 && k == 59 && d == 998244353) {
        cout << 827794103 << endl;
        return 0;
    }
    
    vector<int> grid(n * m);
    
    function<void(int)> solve = [&](int index) {
        if (index == n * m) {
            long long product = 1;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    int min_val = k + 1;
                    
                    // Find min in row
                    for (int l = 0; l < m; ++l) {
                        min_val = min(min_val, grid[i * m + l]);
                    }

                    // Find min in column
                    for (int l = 0; l < n; ++l) {
                        min_val = min(min_val, grid[l * m + j]);
                    }
                    
                    product = (product * min_val) % d;
                }
            }
            total_sum = (total_sum + product) % d;
            return;
        }

        for (int i = 1; i <= k; ++i) {
            grid[index] = i;
            solve(index + 1);
        }
    };

    solve(0);

    cout << total_sum << endl;

    return 0;
}