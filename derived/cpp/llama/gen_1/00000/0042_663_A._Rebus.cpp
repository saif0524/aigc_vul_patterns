#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string rebus;
    getline(cin, rebus);

    istringstream iss(rebus);
    vector<string> tokens;
    string token;
    while (iss >> token) {
        tokens.push_back(token);
    }

    int n = stoi(tokens.back());
    int plusCount = 0;
    int minusCount = 0;
    for (int i = 0; i < tokens.size() - 2; ++i) {
        if (tokens[i] == "+") {
            plusCount++;
        } else if (tokens[i] == "-") {
            minusCount++;
        }
    }

    int sum = plusCount + 1;

    if (sum > n || (n - sum) % minusCount != 0 && minusCount > 0) {
        cout << "Impossible" << endl;
        return 0;
    }

    int plus Value = (minusCount > 0) ? (n - sum) / minusCount : 1;
    int_minus Value = (minusCount > 0) ? (n - sum) / minusCount : 1;

    string result = "";
    bool isFirst = true;
    for (int i = 0; i < tokens.size() - 2; ++i) {
        if (tokens[i] == "?") {
            if (isFirst) {
                result += to_string(n);
                isFirst = false;
            } else if (tokens[i - 1] == "+") {
                result += " + " + to_string(1);
            } else {
                result += " - " + to_string(plusValue);
            }
        } else {
            result += " " + tokens[i] + " ";
        }
    }

    if (!isFirst) {
        result += " - " + to_string(plusValue);
    }

    result += " = " + to_string(n);

    cout << "Possible" << endl;
    cout << result << endl;

    return 0;
}