#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    bool isSubsequence = false;

    int j = 0;
    for (int i = 0; i < s2.length(); i++) {
        if (j < s1.length() && s1[j] == s2[i]) {
            j++;
        }
    }

    if (j == s1.length()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}