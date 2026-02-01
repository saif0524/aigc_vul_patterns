#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_palindrome(const string& s) {
    string reversed_s = s;
    reverse(reversed_s.begin(), reversed_s.end());
    return s == reversed_s;
}

bool is_tolerable(const string& s, int p) {
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] > 'a' + p - 1) {
            return false;
        }
    }
    for (int i = 0; i < s.length(); ++i) {
        for (int j = i + 1; j < s.length(); ++j) {
            string sub = s.substr(i, j - i + 1);
            if (sub.length() >= 2 && is_palindrome(sub)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;

    string next_s = s;
    bool found = false;

    while (true) {
        
        int i = n - 1;
        while (i >= 0 && next_s[i] == 'a' + p - 1) {
            next_s[i] = 'a';
            i--;
        }

        if (i < 0) {
            break;
        }

        next_s[i]++;

        if (is_tolerable(next_s, p)) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << next_s << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}