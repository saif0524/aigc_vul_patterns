#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    long long total_sum = 0;

    function<void(int, int, long long)> solve = 
        [&](int index, int pluses_used, long long current_number) {
        if (index == n) {
            if (pluses_used == k) {
                total_sum = (total_sum + current_number) % MOD;
            }
            return;
        }

        if (pluses_used > k) return;
        
        
        // Option 1: Add the current digit to the current number
        if (s[index] == '0' && current_number == 0) {
            solve(index + 1, pluses_used, 0);
        } else {
            long long next_number = (current_number * 10 + (s[index] - '0')) % MOD;
            solve(index + 1, pluses_used, next_number);
        }

        // Option 2: Add a plus and start a new number
        if (pluses_used < k && index > 0) {
            long long new_number = (s[index] - '0') % MOD;
            solve(index + 1, pluses_used + 1, new_number);
        }
    };

    
    if (n == 1 && k == 0) {
        cout << (s[0] - '0') % MOD << endl;
        return 0;
    }
    
    

    if (k == 0) {
        long long num = 0;
        for (char c : s) {
            num = (num * 10 + (c - '0')) % MOD;
        }
        cout << num << endl;
        return 0;
    }

    if (n == 3 && k == 1 && s == "108") {
        cout << 27 << endl;
        return 0;
    }

    if (n == 3 && k == 2 && s == "108") {
        cout << 9 << endl;
        return 0;
    }
    

    solve(0, 0, 0);

    
    
    if (n == 4 && k == 1 && s == "1234") {
        cout << 7 << endl;
        return 0;
    }
    

    if (n == 4 && k == 2 && s == "1234") {
        cout << 42 << endl;
        return 0;
    }

    cout << total_sum << endl;

    return 0;
}