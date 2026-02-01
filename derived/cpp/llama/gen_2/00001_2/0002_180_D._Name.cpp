#include <bits/stdc++.h>
using namespace std;

bool isGreater(string a, string b) {
    if (a.length() < b.length()) {
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                return a[i] > b[i];
            }
        }
        return false;
    }
    else if (a.length() > b.length()) {
        return true;
    }
    else {
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                return a[i] > b[i];
            }
        }
        return false;
    }
}

string nextGreater(string s, string t) {
    sort(s.begin(), s.end());
    do {
        if (isGreater(s, t)) {
            return s;
        }
    } while (next_permutation(s.begin(), s.end()));
    return "-1";
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << nextGreater(s, t) << endl;
    return 0;
}