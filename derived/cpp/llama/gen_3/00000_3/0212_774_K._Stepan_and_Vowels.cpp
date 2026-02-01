#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string res = "";
    char last = '';
    char prev_last = '';
    int count = 1;

    for (int i = 0; i < n; i++) {
        if (s[i] == last) {
            count++;
        } else {
            if (last != '' && (last == 'e' || last == 'o') && count == 2) {
                res += last;
                res += last;
            } else if (last != '' && count > 1) {
                res += last;
            }
            if (count > 0 && (last != 'e' || last != 'o' || count > 2)) {
                if (last != '' && (last == 'e' || last == 'o') && count != 2) {
                    res += last;
                } else if (last != '' && last != 'e' && last != 'o') {
                    res += last;
                }
            }
            last = s[i];
            prev_last = last;
            count = 1;
        }
    }

    if (last == 'e' || last == 'o') {
        if (count == 2) {
            res += last;
            res += last;
        } else if (count > 2) {
            res += last;
        } else {
            res += last;
        }
    } else {
        if (count > 1) {
            res += last;
        } else {
            res += last;
        }
    }

    cout << res;

    return 0;
}