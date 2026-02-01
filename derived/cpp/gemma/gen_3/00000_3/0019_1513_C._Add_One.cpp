#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        string s = to_string(n);
        for (int i = 0; i < m; ++i) {
            string next_s = "";
            for (char c : s) {
                int digit = c - '0';
                int next_digit = (digit + 1) % 10;
                if (digit == 9) {
                    next_s += "10";
                } else {
                    next_s += to_string(next_digit);
                }
            }
            s = next_s;
        }

        cout << s.length() % MOD << endl;
    }

    return 0;
}