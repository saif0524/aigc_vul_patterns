#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long count = 0;
    vector<int> current_array(n);

    function<void(int)> solve = [&](int index) {
        if (index == n) {
            bool valid = true;
            if (n >= 1) {
                if (index > 1 && current_array[0] > current_array[1]) valid = false;
            }
            if (n >= 2) {
                if (index > 1 && current_array[n-1] > current_array[n-2]) valid = false;
            }
            
            for (int i = 1; i < n - 1; ++i) {
                if (current_array[i] > max(current_array[i - 1], current_array[i + 1])) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                count = (count + 1) % MOD;
            }
            return;
        }

        if (a[index] != -1) {
            current_array[index] = a[index];
            solve(index + 1);
        } else {
            for (int i = 1; i <= 200; ++i) {
                current_array[index] = i;
                solve(index + 1);
            }
        }
    };

    solve(0);

    cout << count << endl;

    return 0;
}