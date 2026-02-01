#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int convertToDecimal(const string& str, int radix) {
    int result = 0;
    int power = 1;
    for (int i = str.size() - 1; i >= 0; i--) {
        char c = str[i];
        int digit = (c >= '0' && c <= '9') ? c - '0' : c - 'A' + 10;
        if (digit >= radix) return -1;
        result += digit * power;
        power *= radix;
    }
    return result;
}

int main() {
    string time;
    cin >> time;
    int colonIndex = time.find(':');
    string hours = time.substr(0, colonIndex);
    string minutes = time.substr(colonIndex + 1);

    vector<int> validRadices;

    for (int radix = 2; radix <= 60; radix++) {
        int hourValue = convertToDecimal(hours, radix);
        int minuteValue = convertToDecimal(minutes, radix);

        if (hourValue != -1 && minuteValue != -1) {
            if (hourValue >= 0 && hourValue < 24 && minuteValue >= 0 && minuteValue < 60) {
                validRadices.push_back(radix);
            }
        }
    }

    if (validRadices.size() == 0) {
        cout << "0" << endl;
    } else if (validRadices.size() == 59) {
        cout << "-1" << endl;
    } else {
        for (int i = 0; i < validRadices.size(); i++) {
            cout << validRadices[i];
            if (i < validRadices.size() - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}