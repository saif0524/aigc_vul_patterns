#include <iostream>
#include <string>

using namespace std;

bool isTolerable(const string& s, int p) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] - 'a' >= p) {
            return false;
        }
        for (int j = i + 1; j < s.size(); j++) {
            if (s[i] == s[j]) {
                return false;
            }
        }
    }
    return true;
}

string nextTolerableString(const string& s, int p) {
    string result = s;
    for (int i = s.size() - 1; i >= 0; i--) {
        int nextChar = s[i] - 'a' + 1;
        while (nextChar < p) {
            result[i] = 'a' + nextChar;
            if (isTolerable(result, p)) {
                return result;
            }
            nextChar++;
        }
        result[i] = 'a';
    }
    return "";
}

int main() {
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    string nextString = nextTolerableString(s, p);
    if (nextString.empty()) {
        cout << "NO" << endl;
    } else {
        cout << nextString << endl;
    }
    return 0;
}