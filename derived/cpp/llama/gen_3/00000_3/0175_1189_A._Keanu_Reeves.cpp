#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k = 0;
    string ans = "";
    int z = 0, o = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') z++;
        else o++;
        if (z != o) continue;
        k++;
        ans += s.substr(0, i + 1) + " ";
        s = s.substr(i + 1);
        z = o = 0;
        i = -1;
    }
    if (s.length() > 0) {
        k++;
        ans += s;
    }
    cout << k << endl;
    cout << ans << endl;
    return 0;
}