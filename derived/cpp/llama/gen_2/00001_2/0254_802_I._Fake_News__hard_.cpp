#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string s;
        cin >> s;

        long long ans = 0;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j <= s.size() - i; j++) {
                string p = s.substr(j, i);
                int count = 0;
                for (int k = 0; k <= s.size() - i; k++) {
                    if (s.substr(k, i) == p) {
                        count++;
                    }
                }
                ans += count;
            }
        }

        cout << ans << endl;
    }

    return 0;
}