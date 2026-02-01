#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for (int i = 0; i <= n - m; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (s[i + j]!= t[j]) cnt++;
        }
        if (cnt <= k) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}