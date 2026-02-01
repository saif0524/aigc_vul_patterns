#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (s[i]!= 'r') cnt1++;
            if (s[i]!= 'b') cnt2++;
        } else {
            if (s[i]!= 'b') cnt1++;
            if (s[i]!= 'r') cnt2++;
        }
    }

    std::cout << std::min(cnt1, cnt2) << std::endl;

    return 0;
}