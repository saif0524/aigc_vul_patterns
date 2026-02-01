#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    stringstream ss(input);
    vector<int> numbers;
    vector<char> operations;
    string token;

    while (getline(ss, token, ' ')) {
        if (token == "?" || token == "+" || token == "-" || token == "=") {
            if (token == "?" || token == "+" || token == "-") {
                numbers.push_back(-1);
                if (token == "+") operations.push_back('+');
                if (token == "-") operations.push_back('-');
            } else if (token == "=") {
                break;
            }
        }
    }

    int n;
    ss >> n;

    int q_count = numbers.size();
    if (q_count == 0){
        if (n == 0) cout << "Possible\n0 = 0";
        else cout << "Impossible";
        return 0;
    }

    if (q_count == 1){
        if (n > 0) cout << "Possible\n" << n << " = " << n;
        else cout << "Impossible";
        return 0;
    }

    bool possible = false;
    for (int i = 1; i <= n && !possible; ++i) {
        for (int j = 1; j <= n && !possible; ++j) {
            for (int k = 1; k <= n && !possible; ++k) {
                for (int l = 1; l <= n && !possible; ++l) {
                    for (int m = 1; m <= n && !possible; ++m) {
                        numbers[0] = i, numbers[1] = j, numbers[2] = k, numbers[3] = l, numbers[4] = m;
                        int result = numbers[0];
                        for (int op_idx = 0; op_idx < operations.size(); ++op_idx) {
                            if (operations[op_idx] == '+') {
                                result += numbers[op_idx + 1];
                            } else if (operations[op_idx] == '-') {
                                result -= numbers[op_idx + 1];
                            }
                        }
                        if (result == n) {
                            possible = true;
                            break;
                        }
                    }
                }
            }
        }
    }

    if (possible) {
        cout << "Possible\n";
        for (int i = 0; i < q_count - 1; ++i) {
            cout << numbers[i] << " " << operations[i] << " ";
        }
        cout << numbers.back() << " = " << n;
    } else {
        cout << "Impossible";
    }

    return 0;
}