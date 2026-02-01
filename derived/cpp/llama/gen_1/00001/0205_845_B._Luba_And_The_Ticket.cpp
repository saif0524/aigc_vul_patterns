#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

int main() {
    std::string s;
    std::cin >> s;

    int sum1 = s[0] - '0' + s[1] - '0' + s[2] - '0';
    int sum2 = s[3] - '0' + s[4] - '0' + s[5] - '0';

    if (sum1 == sum2) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int ans = INT_MAX;
    for (int i = 0; i < 1000; i++) {
        std::string t = s;
        int a = i / 100;
        int b = (i / 10) % 10;
        int c = i % 10;

        for (int mask = 0; mask < 8; mask++) {
            int cnt = __builtin_popcount(mask);
            if ((mask & 1) == 1) t[0] = a + '0';
            if ((mask & 2) == 2) t[1] = b + '0';
            if ((mask & 4) == 4) t[2] = c + '0';

            int sum3 = t[0] - '0' + t[1] - '0' + t[2] - '0';
            int sum4 = sum3 - (t[3] - '0') - (t[4] - '0') - (t[5] - '0');
            int d = sum4 / 3;
            int r = sum4 % 3;

            if (r != 0) continue;
            if (d < 0) {
                d = -d;
                for (int j = 3; j < 6; j++) {
                    if (d == 0) break;
                    if (t[j] - '0' < 9) {
                        t[j] = std::min(t[j] - '0' + d, 9) + '0';
                        d -= std::min(d, 9 - (t[j] - '0'));
                        cnt++;
                    }
                }
            }
            else {
                for (int j = 3; j < 6; j++) {
                    if (t[j] - '0' > d) {
                        t[j] = d + '0';
                        cnt++;
                        break;
                    }
                }
            }

            ans = std::min(ans, cnt);
        }
    }

    for (int i = 0; i < 1000; i++) {
        std::string t = s;
        int a = i / 100;
        int b = (i / 10) % 10;
        int c = i % 10;

        for (int mask = 0; mask < 8; mask++) {
            int cnt = __builtin_popcount(mask);
            if ((mask & 1) == 1) t[3] = a + '0';
            if ((mask & 2) == 2) t[4] = b + '0';
            if ((mask & 4) == 4) t[5] = c + '0';

            int sum3 = t[3] - '0' + t[4] - '0' + t[5] - '0';
            int sum4 = sum3 - (t[0] - '0') - (t[1] - '0') - (t[2] - '0');
            int d = sum4 / 3;
            int r = sum4 % 3;

            if (r != 0) continue;
            if (d < 0) {
                d = -d;
                for (int j = 0; j < 3; j++) {
                    if (d == 0) break;
                    if (t[j] - '0' < 9) {
                        t[j] = std::min(t[j] - '0' + d, 9) + '0';
                        d -= std::min(d, 9 - (t[j] - '0'));
                        cnt++;
                    }
                }
            }
            else {
                for (int j = 0; j < 3; j++) {
                    if (t[j] - '0' > d) {
                        t[j] = d + '0';
                        cnt++;
                        break;
                    }
                }
            }

            ans = std::min(ans, cnt);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}