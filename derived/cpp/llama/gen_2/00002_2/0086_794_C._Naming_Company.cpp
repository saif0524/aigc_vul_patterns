#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s, t;
    std::cin >> s >> t;

    int n = s.size();
    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end(), std::greater<char>());

    std::string ans(n, '?');
    int l = 0, r = n - 1;
    int i = 0, j = 0, k = n - 1;

    for (int turn = 0; turn < n; turn++) {
        if (turn % 2 == 0) {
            if (s[i] < t[k]) {
                ans[l++] = s[i++];
            } else {
                ans[r--] = s[j--];
            }
        } else {
            if (t[k] > s[j]) {
                ans[l++] = t[k--];
            } else {
                ans[r--] = t[i++];
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}