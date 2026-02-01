#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;

    for (int i = 0; i < s.length(); i++) {
        if (i % 2 == k % 2) {
            if (islower(s[i])) {
                s[i] = toupper(s[i]);
            }
        }
    }

    cout << s << endl;

    return 0;
}