#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t;
    while (getline(cin, s) && getline(cin, t)) {
        int n = s.length();
        int m = t.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int k = 0;
                while (i + k < n && j + k < m && s[i + k] == t[j + k]) {
                    k++;
                }
                ans = max(ans, k);
            }
        }
        cout << ans << endl;
    }
    return 0;
}