#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(const string& s) {
    string reversed_s = s;
    reverse(reversed_s.begin(), reversed_s.end());
    return s == reversed_s && s.length() > 1;
}

bool is_good(const string& s) {
    if (s.empty()) return false; 
    
    for (int i = 0; i < s.length(); ++i) {
        bool found_palindrome = false;
        for (int j = 0; j < s.length(); ++j) {
            for (int k = j + 1; k < s.length(); ++k) {
                if (is_palindrome(s.substr(j, k - j + 1))) {
                    if (s.substr(j, k - j + 1).find(s[i]) != string::npos) {
                        found_palindrome = true;
                        break;
                    }
                }
            }
            if (found_palindrome) break;
        }
        if (!found_palindrome) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (is_good(s.substr(i, j - i + 1))) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}