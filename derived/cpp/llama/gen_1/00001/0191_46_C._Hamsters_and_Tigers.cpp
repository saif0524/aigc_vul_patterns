#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int h = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'H') h++;
    }
    int ans = n;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < h; ++j) {
            if (s[(i + j) % n] == 'T') cnt++;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}