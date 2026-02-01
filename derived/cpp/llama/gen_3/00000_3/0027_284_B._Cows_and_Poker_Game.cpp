#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            if (i != j && s[j] != 'A' && s[j] != 'F') {
                ok = false;
                break;
            }
        }
        if (ok && (s[i] == 'A' || s[i] == 'I')) {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}