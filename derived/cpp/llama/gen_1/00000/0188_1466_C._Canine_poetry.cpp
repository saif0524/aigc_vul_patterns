#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int result = 0;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1] || (i >= 2 && s[i] == s[i - 2])) {
                s[i] = '=';
                result++;
            }
        }

        cout << result << endl;
    }

    return 0;
}