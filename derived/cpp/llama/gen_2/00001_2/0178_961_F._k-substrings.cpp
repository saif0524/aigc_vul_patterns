#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < n - 1; i++) {
        string substr = s.substr(i, n - i);
        int max_len = -1;
        for (int len = substr.length() - 1; len > 0; len -= 2) {
            string pref = substr.substr(0, len);
            if (substr.length() > pref.length() && substr.substr(substr.length() - len) == pref) {
                max_len = len;
                break;
            }
        }
        cout << max_len << " ";
    }
    return 0;
}