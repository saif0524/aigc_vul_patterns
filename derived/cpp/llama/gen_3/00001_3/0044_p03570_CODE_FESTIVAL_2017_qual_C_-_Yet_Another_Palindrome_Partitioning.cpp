#include <iostream>
#include <string>
using namespace std;

int checkPalindrome(string str) {
    int oddCount = 0;
    int charCount[26] = {0};

    for (int i = 0; i < str.length(); i++) {
        charCount[str[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (charCount[i] % 2 != 0) {
            oddCount++;
        }
    }

    if (oddCount <= 1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    string s;
    cin >> s;

    int N = 0;
    while (s.length() > 0) {
        for (int i = s.length(); i > 0; i--) {
            string substr = s.substr(0, i);
            if (checkPalindrome(substr)) {
                N++;
                s = s.substr(i);
                break;
            }
        }
    }

    cout << N << endl;

    return 0;
}