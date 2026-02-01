#include <iostream>
#include <string>

using namespace std;

bool isGood(const string& s) {
    string t;
    for (char c : s) {
        if (t.empty() || t.back() != c) {
            t += c;
        }
    }
    int i = 0, j = t.size() - 1;
    while (i < j) {
        if (t[i] != t[j]) {
            return false;
        }
        i++, j--;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    int even = 0, odd = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j <= s.size(); j++) {
            string t = s.substr(i, j - i);
            if (isGood(t)) {
                if (t.size() % 2 == 0) {
                    even++;
                } else {
                    odd++;
                }
            }
        }
    }
    cout << even << " " << odd << endl;
    return 0;
}