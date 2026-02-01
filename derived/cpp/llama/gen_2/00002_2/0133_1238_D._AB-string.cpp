#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            bool good = true;
            for (int k = i; k < j; k++) {
                bool found = false;
                for (int len = 2; len <= j - k; len++) {
                    string t = s.substr(k, len);
                    string rev = t;
                    reverse(rev.begin(), rev.end());
                    if (t == rev) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    good = false;
                    break;
                }
            }
            if (good) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}