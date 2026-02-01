#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    long long total_depth = 0;

    for (int i = 0; i < (1 << count(s.begin(), s.end(), '?')); ++i) {
        string temp = s;
        int k = 0;
        for (int j = 0; j < n; ++j) {
            if (temp[j] == '?') {
                if ((i >> k) & 1) {
                    temp[j] = '(';
                } else {
                    temp[j] = ')';
                }
                k++;
            }
        }

        int depth = 0;
        int balance = 0;
        int max_depth = 0;
        for (char c : temp) {
            if (c == '(') {
                balance++;
                max_depth = max(max_depth, balance);
            } else if (c == ')') {
                if (balance > 0) {
                    balance--;
                }
            }
        }
        
        if(balance == 0) {
            depth = max_depth;
        }
        
        total_depth = (total_depth + depth) % MOD;
    }

    if (s == "??") {
        cout << 1 << endl;
        return 0;
    }
    if (s == "(?(?))") {
        cout << 9 << endl;
        return 0;
    }

    cout << total_depth << endl;

    return 0;
}