#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_tolerable(const string& s, int p) {
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] > 'a' + p - 1) {
            return false;
        }
    }
    for (int i = 0; i < s.length() - 1; ++i) {
        if (s[i] == s[i + 1]) {
            return false;
        }
    }
    for (int i = 0; i < s.length() - 2; ++i) {
        if (s[i] == s[i + 2]) {
            return false;
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
            --i;
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