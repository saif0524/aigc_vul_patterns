#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> s(k);
    for (int i = 0; i < k; ++i) {
        cin >> s[i];
    }

    int ans = 0;
    for (int i = 0; i < n - m + 1; ++i) {
        for (int j = 0; j < n - m + 1; ++j) {
            int cnt = 0;
            for (int x = 0; x < m; ++x) {
                for (int y = 0; y < m; ++y) {
                    if (s[0][x * m + y] != 'a') {
                        ++cnt;
                    }
                }
            }
            for (int l = 1; l < k; ++l) {
                int cur_cnt = 0;
                for (int x = 0; x < m; ++x) {
                    for (int y = 0; y < m; ++y) {
                        if (s[l][x * m + y] == 'a') {
                            ++cur_cnt;
                        }
                    }
                }
                cnt = min(cnt, cur_cnt);
            }
            ans = max(ans, cnt);
        }
    }

    if (ans == 0) {
        cout << "-1";
    } else {
        cout << "1 " << ans;
    }
    cout << "\n";

    return 0;
}