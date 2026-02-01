#include <bits/stdc++.h>
using namespace std;

string reverseString(const string& s) {
    string reversed = s;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

string rotateLeft(const string& s) {
    return s.substr(1) + s[0];
}

string rotateRight(const string& s) {
    return s.back() + s.substr(0, s.size() - 1);
}

string swapHalves(const string& s) {
    int mid = s.size() / 2;
    if (s.size() % 2 == 0) {
        return s.substr(mid) + s.substr(0, mid);
    } else {
        return s.substr(mid + 1) + s[mid] + s.substr(0, mid);
    }
}

string incrementDigits(const string& s) {
    string incremented = s;
    for (char& c : incremented) {
        if (isdigit(c)) {
            c = (c - '0' + 1) % 10 + '0';
        }
    }
    return incremented;
}

string decrementDigits(const string& s) {
    string decremented = s;
    for (char& c : decremented) {
        if (isdigit(c)) {
            c = (c - '0' - 1 + 10) % 10 + '0';
        }
    }
    return decremented;
}

string applyReverse(const string& s) {
    return reverseString(s);
}

string applyRotateLeft(const string& s) {
    return rotateLeft(s);
}

string applyRotateRight(const string& s) {
    return rotateRight(s);
}

string applySwapHalves(const string& s) {
    return swapHalves(s);
}

string applyIncrementDigits(const string& s) {
    return incrementDigits(s);
}

string applyDecrementDigits(const string& s) {
    return decrementDigits(s);
}

string applyOperation(const string& s, char op) {
    switch (op) {
        case 'A': return applyReverse(s);
        case 'J': return applyRotateLeft(s);
        case 'M': return applyDecrementDigits(s);
        case 'P': return applyIncrementDigits(s);
        case 'C': return applyRotateRight(s);
        case 'E': return applySwapHalves(s);
        default: return s;
    }
}

string reverseOperations(const string& s, const string& order) {
    string result = s;
    for (auto it = order.rbegin(); it != order.rend(); ++it) {
        result = applyOperation(result, *it);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string order, message;
        cin >> order >> message;
        cout << reverseOperations(message, order) << endl;
    }
    return 0;
}