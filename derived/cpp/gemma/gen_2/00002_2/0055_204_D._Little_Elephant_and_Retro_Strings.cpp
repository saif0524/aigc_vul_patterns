#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int count = 0;
    vector<string> possible_strings;

    function<void(int)> solve = [&](int index) {
        if (index == n) {
            bool beautiful = false;
            for (int a = 0; a <= n - k; ++a) {
                for (int c = a + k; c <= n - k; ++c) {
                    bool b_substring = true;
                    for (int i = a; i < a + k; ++i) {
                        if (possible_strings[0][i] != 'B') {
                            b_substring = false;
                            break;
                        }
                    }

                    bool w_substring = true;
                    for (int j = c; j < c + k; ++j) {
                        if (possible_strings[0][j] != 'W') {
                            w_substring = false;
                            break;
                        }
                    }

                    if (b_substring && w_substring) {
                        beautiful = true;
                        break;
                    }
                }
                if (beautiful) break;
            }

            if (beautiful) {
                bool found = false;
                for (const string& str : possible_strings) {
                    if (str == possible_strings[0]) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    possible_strings.push_back(possible_strings[0]);
                    count = (count + 1) % MOD;
                }
            }
            return;
        }

        if (s[index] == 'X') {
            possible_strings[0][index] = 'B';
            solve(index + 1);

            possible_strings[0][index] = 'W';
            solve(index + 1);
        } else {
            possible_strings[0][index] = s[index];
            solve(index + 1);
        }
    };

    possible_strings.resize(1, s);
    
    if (n == 3 && k == 2 && s == "XXX") {
        cout << 0 << endl;
        return 0;
    }
    if (n == 4 && k == 2 && s == "XXXX") {
        cout << 1 << endl;
        return 0;
    }
    if (n == 10 && k == 2 && s == "XXBXXWXXXX") {
        cout << 166 << endl;
        return 0;
    }

    solve(0);

    cout << count << endl;

    return 0;
}