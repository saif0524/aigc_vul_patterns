#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        string num;
        cin >> num;
        bool valid = true;
        for (char c : num) {
            if (c - '0' > k) {
                valid = false;
                break;
            }
        }
        if (valid) {
            set<char> digits(num.begin(), num.end());
            for (int j = 0; j <= k; ++j) {
                if (digits.find(char('0' + j)) == digits.end()) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}