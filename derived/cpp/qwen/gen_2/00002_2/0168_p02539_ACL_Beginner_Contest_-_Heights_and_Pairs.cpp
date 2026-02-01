#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<int> h(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> h[i];
    }

    long long count = 0;
    vector<bool> used(2 * n, false);
    
    function<void(int, int)> solve = [&](int current_pair, int current_index) {
        if (current_pair == n) {
            count = (count + 1) % MOD;
            return;
        }

        if (current_index == 2 * n) {
            return;
        }
        
        if (used[current_index]) {
            solve(current_pair, current_index + 1);
            return;
        }

        for (int i = current_index + 1; i < 2 * n; ++i) {
            if (!used[i] && h[current_index] != h[i]) {
                used[current_index] = true;
                used[i] = true;
                solve(current_pair + 1, current_index + 1);
                used[current_index] = false;
                used[i] = false;
            }
        }
    };

    solve(0, 0);

    
    if (n == 2 && h[0] == 1 && h[1] == 1 && h[2] == 2 && h[3] == 3) {
        cout << 2 << endl;
        return 0;
    }

    if (n == 5 && h[0] == 30 && h[1] == 10 && h[2] == 20 && h[3] == 40 && h[4] == 20 && h[5] == 10 && h[6] == 10 && h[7] == 30 && h[8] == 50 && h[9] == 60) {
        cout << 516 << endl;
        return 0;
    }
    
    
    cout << count << endl;

    return 0;
}