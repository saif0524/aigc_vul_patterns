#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> a, b;
    for (int i = 0; i < 6; i++) {
        int x, y;
        std::cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    if (a[0] == a[1] && a[1] == a[2] && a[3] == a[4] && a[4] == a[5] &&
        b[0] == b[1] && b[1] == b[2] && b[3] == b[4] && b[4] == b[5] &&
        a[0] == b[0] && a[5] == b[5]) {
        std::cout << "yes" << std::endl;
    } else if (a[0] == a[1] && a[1] == a[2] && a[3] == a[4] && a[4] == a[5] &&
               b[0] == b[1] && b[2] == b[3] && b[3] == b[4] && b[4] == b[5] &&
               a[0] == b[2] && a[5] == b[0]) {
        std::cout << "yes" << std::endl;
    } else if (a[0] == a[1] && a[1] == a[2] && a[3] == a[4] && a[4] == a[5] &&
               b[0] == b[1] && b[1] == b[2] && b[3] == b[4] && b[4] == b[5] &&
               a[0] == b[0] && a[5] == b[5]) {
        std::cout << "yes" << std::endl;
    } else {
        std::vector<std::pair<int, int>> c;
        for (int i = 0; i < 6; i++) {
            c.push_back(std::make_pair(a[i], b[i]));
        }

        std::sort(c.begin(), c.end());

        int f1 = 0, f2 = 0, f3 = 0;
        for (int i = 0; i < 6; i++) {
            if (c[i].first == c[0].first && c[i].second == c[0].second) f1++;
            else if (c[i].first == c[1].first && c[i].second == c[1].second) f2++;
            else if (c[i].first == c[2].first && c[i].second == c[2].second) f3++;
        }

        if (f1 == 2 && f2 == 2 && f3 == 2 && c[0].first == c[1].second && c[1].first == c[2].second && c[2].first == c[0].second) {
            std::cout << "yes" << std::endl;
        } else if (f1 == 2 && f2 == 2 && f3 == 2 && c[0].first == c[2].second && c[2].first == c[1].second && c[1].first == c[0].second) {
            std::cout << "yes" << std::endl;
        } else if (f1 == 2 && f2 == 2 && f3 == 2 && c[0].first == c[1].second && c[1].first == c[0].second && c[2].first == c[2].second) {
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }

    return 0;
}