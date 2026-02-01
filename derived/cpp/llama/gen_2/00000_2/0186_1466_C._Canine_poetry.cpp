#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if ((i > 0 && s[i] == s[i - 1]) || (i > 1 && s[i] == s[i - 2])) {
                s[i] = '*';
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}