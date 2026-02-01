#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    stringstream ss(input);
    string token;
    vector<int> nums;
    vector<char> ops;
    int n;

    while (getline(ss, token, ' ')) {
        if (token == "+" || token == "-") {
            ops.push_back(token[0]);
        } else if (token.back() == '=') {
            n = stoi(token.substr(0, token.size() - 1));
        } else {
            nums.push_back(stoi(token));
        }
    }

    if (nums.size() == 1) {
        cout << "Possible\n" << n << " = " << n << endl;
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < ops.size(); ++i) {
        int val = (ops[i] == '+') ? 1 : -1;
        sum += val;
    }

    if (abs(sum) > n || (n + sum) % 2 != 0) {
        cout << "Impossible" << endl;
        return 0;
    }

    int base = (n + sum) / 2;
    vector<int> result(nums.size(), 1);
    result[0] = base;

    for (int i = 0; i < ops.size(); ++i) {
        int val = (ops[i] == '+') ? 1 : -1;
        base -= val;
        result[i + 1] = base;
    }

    for (int num : result) {
        if (num <= 0 || num > n) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    cout << "Possible\n";
    cout << result[0];
    for (int i = 0; i < ops.size(); ++i) {
        cout << " " << ops[i] << " " << result[i + 1];
    }
    cout << " = " << n << endl;

    return 0;
}