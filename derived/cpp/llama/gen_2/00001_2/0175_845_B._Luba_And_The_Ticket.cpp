#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string ticket;
    std::cin >> ticket;

    int ans = 3;
    for (int mask = 0; mask < (1 << 6); ++mask) {
        int temp = mask;
        int cnt = 0;
        while (temp > 0) {
            cnt += temp % 2;
            temp /= 2;
        }

        std::string new_ticket = ticket;
        for (int i = 0; i < 6; ++i) {
            if ((mask >> i) & 1) {
                if (i < 3) {
                    new_ticket[i] = '0' + (9 - (new_ticket[3] - '0') - (new_ticket[4] - '0') - (new_ticket[5] - '0') - ((new_ticket[0] - '0') + (new_ticket[1] - '0') + (new_ticket[2] - '0') - (i > 0) * (new_ticket[0] - '0') - (i > 1) * (new_ticket[1] - '0') - (i > 2) * (new_ticket[2] - '0'))) / 3;
                } else {
                    new_ticket[i] = '0' + (9 - (new_ticket[0] - '0') - (new_ticket[1] - '0') - (new_ticket[2] - '0') - ((new_ticket[3] - '0') + (new_ticket[4] - '0') + (new_ticket[5] - '0') - (i > 3) * (new_ticket[3] - '0') - (i > 4) * (new_ticket[4] - '0') - (i > 5) * (new_ticket[5] - '0'))) / 3;
                }
            }
        }

        int sum_first = 0, sum_last = 0;
        for (int i = 0; i < 3; ++i) {
            sum_first += (new_ticket[i] - '0');
            sum_last += (new_ticket[i + 3] - '0');
        }

        if (sum_first == sum_last) {
            ans = std::min(ans, cnt);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}