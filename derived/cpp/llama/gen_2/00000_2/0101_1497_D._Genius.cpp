#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> tag(n), s(n);
        for (int i = 0; i < n; i++) {
            cin >> tag[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (tag[i] != tag[j]) {
                    ans = max(ans, abs(s[i] - s[j]));
                    for (int k = 0; k < n; k++) {
                        if (k != i && k != j && tag[k] != tag[i] && tag[k] != tag[j] && abs(pow(2, i + 1) - pow(2, j + 1)) > abs(pow(2, k + 1) - pow(2, i + 1))) {
                            ans = max(ans, abs(s[i] - s[j]) + abs(s[j] - s[k]));
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}