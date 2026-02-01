#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int ans = -1;
    std::set<int> s;
    for (int i = 0; i < n; ++i) {
        if (a[i] > i) {
            ans = i + 1;
            break;
        }
        if (s.find(a[i]) != s.end()) {
            bool found = false;
            for (int j = 0; j <= i; ++j) {
                if (s.find(j) == s.end()) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                ans = i + 1;
                break;
            }
        }
        s.insert(a[i]);
    }

    std::cout << ans << std::endl;

    return 0;
}