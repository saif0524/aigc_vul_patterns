#include <iostream>
#include <string>

using namespace std;

bool isPalindrom(const string& s, int i, int j) {
    if (j - i < 2) return false;
    int left = i;
    int right = j;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

bool isValid(const string& s) {
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == s[i + 1]) return false;
    }
    for (int i = 0; i < s.size() - 2; i++) {
        if (s[i] == s[i + 2]) return false;
    }
    return true;
}

bool isLast(const string& s, int p) {
    for (char c : s) {
        if (c - 'a' < p - 1) return false;
    }
    return true;
}

string nextString(const string& s, int n, int p) {
    string nextS = s;
    for (int i = n - 1; i >= 0; i--) {
        int pos = nextS[i] - 'a' + 1;
        if (pos < p) {
            nextS[i] = 'a' + pos;
            for (int j = i + 1; j < n; j++) {
                nextS[j] = 'a';
            }
            while (!isValid(nextS)) {
                for (int j = n - 1; j > i; j--) {
                    if (nextS[j] - 'a' < p - 1) {
                        nextS[j] = 'a' + (nextS[j] - 'a' + 1);
                        for (int k = j + 1; k < n; k++) {
                            nextS[k] = 'a';
                        }
                        break;
                    }
                }
            }
            return nextS;
        }
    }
    return "";
}

int main() {
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    string nextS = nextString(s, n, p);
    if (nextS.empty()) {
        cout << "NO" << endl;
    } else {
        cout << nextS << endl;
    }
    return 0;
}