#include <iostream>
#include <algorithm>

using namespace std;

int rev(int x) {
    int res = 0;
    while (x > 0) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int main() {
    int maxx, maxy, w;
    cin >> maxx >> maxy >> w;

    int best_x = -1;
    int best_y = -1;
    int min_tickets = -1;

    for (int x = 1; x <= maxx; ++x) {
        for (int y = 1; y <= maxy; ++y) {
            int lucky_count = 0;
            for (int a = 1; a <= x; ++a) {
                for (int b = 1; b <= y; ++b) {
                    if (a * b == rev(a) * rev(b)) {
                        lucky_count++;
                    }
                }
            }

            if (lucky_count >= w) {
                int total_tickets = x * y;
                if (best_x == -1 || total_tickets < min_tickets) {
                    best_x = x;
                    best_y = y;
                    min_tickets = total_tickets;
                }
            }
        }
    }

    if (best_x == -1) {
        cout << -1 << endl;
    } else {
        cout << best_x << " " << best_y << endl;
    }

    return 0;
}