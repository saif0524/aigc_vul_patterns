#include <iostream>
#include <string>
#include <vector>

using namespace std;

string undo_J(string s) {
    return s.substr(s.size() - 1) + s.substr(0, s.size() - 1);
}

string undo_C(string s) {
    return s.substr(1) + s.substr(0, 1);
}

string undo_E(string s) {
    if (s.size() % 2 == 0)
        return s.substr(s.size() / 2) + s.substr(0, s.size() / 2);
    else
        return s.substr(s.size() / 2 + 1) + s.substr(s.size() / 2, 1) + s.substr(0, s.size() / 2);
}

string undo_A(string s) {
    reverse(s.begin(), s.end());
    return s;
}

string undo_P(string s) {
    for (char &c : s) {
        if (c >= '0' && c <= '9') {
            if (c == '0') c = '9';
            else c--;
        }
    }
    return s;
}

string undo_M(string s) {
    for (char &c : s) {
        if (c >= '0' && c <= '9') {
            if (c == '9') c = '0';
            else c++;
        }
    }
    return s;
}

string undo(string s, char m) {
    switch (m) {
        case 'J': return undo_J(s);
        case 'C': return undo_C(s);
        case 'E': return undo_E(s);
        case 'A': return undo_A(s);
        case 'P': return undo_P(s);
        case 'M': return undo_M(s);
    }
    return s;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string order, message;
        cin >> order >> message;
        for (auto it = order.rbegin(); it != order.rend(); ++it) {
            message = undo(message, *it);
        }
        cout << message << endl;
    }
    return 0;
}