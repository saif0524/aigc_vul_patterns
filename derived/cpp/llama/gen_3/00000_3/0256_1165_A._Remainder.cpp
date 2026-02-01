#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x, y;
    string number;

    cin >> n >> x >> y;
    cin >> number;

    string ynumber = string(y, '0');
    ynumber.insert(ynumber.begin(), 1);

    int result1 = 0, result2 = 0;

    for (int i = 0; i < number.size() - x; i++) {
        if (number[i] == '0') {
            result1++;
        }
    }

    for (int i = number.size() - x; i < number.size(); i++) {
        if (i - number.size() + x < ynumber.size()) {
            if (number[i] != ynumber[i - number.size() + x]) {
                result1++;
            }
        } else {
            if (number[i] != '0') {
                result1++;
            }
        }
    }

    for (int i = 0; i < number.size(); i++) {
        if (number[i] == '0') {
            result2++;
        }
    }

    for (int i = number.size() - x; i < number.size(); i++) {
        if (i - number.size() + x < ynumber.size()) {
            if (number[i] == ynumber[i - number.size() + x]) {
                result2--;
            }
        }
    }

    cout << (result1 < result2 ? result1 : result2);

    return 0;
}