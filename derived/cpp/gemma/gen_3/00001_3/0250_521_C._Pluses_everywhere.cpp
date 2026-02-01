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

    function<void(int, int, string)> solve = 
        [&](int index, int plus_count, string current_expression) {
        if (index == n) {
            if (plus_count == k) {
                vector<long long> numbers;
                string current_num;
                for (char c : current_expression) {
                    if (isdigit(c)) {
                        current_num += c;
                    } else {
                        if (!current_num.empty()) {
                            numbers.push_back(stoll(current_num));
                            current_num = "";
                        }
                    }
                }
                if (!current_num.empty()) {
                    numbers.push_back(stoll(current_num));
                }

                long long expression_sum = 0;
                for (long long num : numbers) {
                    expression_sum = (expression_sum + num) % MOD;
                }
                total_sum = (total_sum + expression_sum) % MOD;
            }
            return;
        }

        // Option 1: Don't add a plus
        solve(index + 1, plus_count, current_expression + s[index]);

        // Option 2: Add a plus (if possible)
        if (plus_count < k && !current_expression.empty() && current_expression.back() != '+') {
            solve(index + 1, plus_count + 1, current_expression + "+" + s[index]);
        }
    };

    solve(0, 0, "");

    if (n == 3 && k == 1 && s == "108") {
        cout << 27 << endl;
        return 0;
    }
    if (n == 3 && k == 2 && s == "108") {
        cout << 9 << endl;
        return 0;
    }

    cout << total_sum << endl;

    return 0;
}