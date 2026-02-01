#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string rotate_left(string s) {
    if (s.empty()) return s;
    char first = s[0];
    for (int i = 0; i < s.length() - 1; ++i) {
        s[i] = s[i + 1];
    }
    s[s.length() - 1] = first;
    return s;
}

string rotate_right(string s) {
    if (s.empty()) return s;
    char last = s[s.length() - 1];
    for (int i = s.length() - 1; i > 0; --i) {
        s[i] = s[i - 1];
    }
    s[0] = last;
    return s;
}

string swap_halves(string s) {
    int len = s.length();
    int mid = len / 2;
    string first_half = s.substr(0, mid);
    string second_half = s.substr(mid);
    if (len % 2 != 0) {
        return second_half + s[mid] + first_half;
    } else {
        return second_half + first_half;
    }
}

string reverse_string(string s) {
    reverse(s.begin(), s.end());
    return s;
}

string increment_digits(string s) {
    for (char& c : s) {
        if (isdigit(c)) {
            if (c == '9') {
                c = '0';
            } else {
                c++;
            }
        }
    }
    return s;
}

string decrement_digits(string s) {
    for (char& c : s) {
        if (isdigit(c)) {
            if (c == '0') {
                c = '9';
            } else {
                c--;
            }
        }
    }
    return s;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        string order;
        string message;
        cin >> order >> message;

        string original_message = message;
        for (int i = order.length() - 1; i >= 0; --i) {
            char messenger = order[i];
            if (messenger == 'J') {
                original_message = rotate_right(original_message);
            } else if (messenger == 'C') {
                original_message = rotate_left(original_message);
            } else if (messenger == 'E') {
                original_message = swap_halves(original_message);
            } else if (messenger == 'A') {
                original_message = reverse_string(original_message);
            } else if (messenger == 'P') {
                original_message = decrement_digits(original_message);
            } else if (messenger == 'M') {
                original_message = increment_digits(original_message);
            }
        }

        cout << original_message << endl;
    }

    return 0;
}