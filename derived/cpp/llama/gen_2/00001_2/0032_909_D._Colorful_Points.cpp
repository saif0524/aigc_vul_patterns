#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 0;
    while (true) {
        string t = s;
        for (int i = 0; i < s.size(); ++i) {
            if (i > 0 && s[i-1] != s[i]) {
                t[i] = '#';
            }
            if (i < s.size() - 1 && s[i+1] != s[i]) {
                t[i] = '#';
            }
        }
        string a;
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] != '#') {
                a += t[i];
            }
        }
        if (a == s) break;
        s = a;
        ans++;
    }
    cout << ans << endl;
    return 0;
}