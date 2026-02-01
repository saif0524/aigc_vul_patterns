#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string reverse_string(string s) {
    reverse(s.begin(), s.end());
    return s;
}

string rotate_left(string s) {
    if (s.empty()) return s;
    char first_char = s[0];
    for (size_t i = 0; i < s.length() - 1; ++i) {
        s[i] = s[i + 1];
    }
    s[s.length() - 1] = first_char;
    return s;
}

string rotate_right(string s) {
    if (s.empty()) return s;
    char last_char = s[s.length() - 1];
    for (size_t i = s.length() - 1; i > 0; --i) {
        s[i] = s[i - 1];
    }
    s[0] = last_char;
    return s;
}

string swap_halves(string s) {
    size_t len = s.length();
    size_t mid = len / 2;
    string first_half = s.substr(0, mid);
    string second_half = s.substr(mid);
    if (len % 2 != 0) {
        return second_half + s[mid] + first_half;
    } else {
        return second_half + first_half;
    }
}

string increment_digits(string s) {
    for (char& c : s) {
        if (isdigit(c)) {
            c = (c == '9') ? '0' : c + 1;
        }
    }
    return s;
}

string decrement_digits(string s) {
    for (char& c : s) {
        if (isdigit(c)) {
            c = (c == '0') ? '9' : c - 1;
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
                original_message = increment_digits(original_message);
            } else if (messenger == 'M') {
                original_message = decrement_digits(original_message);
            }
        }

        cout << original_message << endl;
    }

    return 0;
}