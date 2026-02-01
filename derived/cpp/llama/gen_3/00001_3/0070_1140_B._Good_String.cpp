#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = n;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string sub = s.substr(i, j - i + 1);
                bool ok = true;
                for (int k = 0; k < sub.size() - 1; k++) {
                    if (sub[k] == '<' && sub[k + 1] == '>') {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    ans = min(ans, n - (j - i + 1));
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}