#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if ((s[i] == 'b' && s[n - i - 1]!= 'd') ||
            (s[i] == 'd' && s[n - i - 1]!= 'b') ||
            (s[i] == 'p' && s[n - i - 1]!= 'q') ||
            (s[i] == 'q' && s[n - i - 1]!= 'p')) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}