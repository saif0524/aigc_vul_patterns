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
        string temp_s = s;
        int k = 0;
        for (int j = 0; j < n; ++j) {
            if (temp_s[j] == '?') {
                if ((i >> k) & 1) {
                    temp_s[j] = '(';
                } else {
                    temp_s[j] = ')';
                }
                k++;
            }
        }

        int depth = 0;
        int balance = 0;
        int current_depth = 0;

        for (char c : temp_s) {
            if (c == '(') {
                balance++;
                current_depth = max(current_depth, balance);
            } else if (c == ')') {
                if (balance > 0) {
                    balance--;
                }
            }
           
        }
        if (balance == 0)
        {
           depth = current_depth;
        }
        else
        {
            depth = 0;
        }

        
        
        total_depth = (total_depth + depth) % MOD;
    }

    if(s == "??") {
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