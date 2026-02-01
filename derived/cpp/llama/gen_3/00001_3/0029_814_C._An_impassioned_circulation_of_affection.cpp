#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int m;
        char c;
        cin >> m >> c;

        int ans = 0;
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            for (int k = j; k < n; k++) {
                if (s[k] == c) {
                    cnt++;
                } else if (cnt + m >= k - j + 1) {
                    cnt++;
                } else {
                    break;
                }
                ans = max(ans, cnt);
            }
        }
        cout << ans << endl;
    }

    return 0;
}