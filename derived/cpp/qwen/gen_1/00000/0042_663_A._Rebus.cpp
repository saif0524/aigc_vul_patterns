#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    stringstream ss(input);
    vector<int> numbers;
    vector<char> operations;
    string token;
    int n;

    while (getline(ss, token, ' ')) {
        if (token == "=") {
            ss >> n;
            break;
        }
        if (token == "+" || token == "-") {
            operations.push_back(token[0]);
        } else {
            numbers.push_back(0); // Placeholder for ?
        }
    }

    int sz = numbers.size();
    if (sz == 1) {
        if (n == 0) {
            cout << "Impossible";
        } else {
            cout << "Possible\n" << n << " = " << n;
        }
        return 0;
    }

    vector<int> solution(sz, 1);
    int sum = sz; // Initial sum when all numbers are 1

    for (int i = 0; i < sz; ++i) {
        if (i > 0 && operations[i-1] == '-') {
            sum -= 2; // Adjust for subtraction
        }
        int need = n - sum;
        if (need > 0 && need <= n) {
            solution[i] += need;
            break;
        }
        if (i < sz - 1) {
            sum += n - 1; // Maximize the current number
            solution[i] = n;
        }
    }

    sum = solution[0];
    for (int i = 1; i < sz; ++i) {
        if (operations[i-1] == '+') {
            sum += solution[i];
        } else {
            sum -= solution[i];
        }
    }

    if (sum == n) {
        cout << "Possible\n";
        for (int i = 0; i < sz; ++i) {
            if (i > 0) cout << " " << operations[i-1] << " ";
            cout << solution[i];
        }
        cout << " = " << n;
    } else {
        cout << "Impossible";
    }

    return 0;
}