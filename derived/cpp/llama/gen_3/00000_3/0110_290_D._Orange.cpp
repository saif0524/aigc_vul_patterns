#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;

    for (int i = 0; i < s.length(); i++) {
        if (i % n == 0) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] = toupper(s[i]);
            }
        }
    }
    cout << s;
    return 0;
}