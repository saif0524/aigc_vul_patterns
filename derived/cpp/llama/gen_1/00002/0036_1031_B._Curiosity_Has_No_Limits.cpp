#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n - 1);
    for (int i = 0; i < n - 1; i++) {
        std::cin >> a[i];
    }

    std::vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        std::cin >> b[i];
    }

    for (int t1 = 0; t1 <= 3; t1++) {
        std::vector<int> t(n);
        t[0] = t1;

        bool possible = true;
        for (int i = 1; i < n; i++) {
            bool found = false;
            for (int t2 = 0; t2 <= 3; t2++) {
                if ((t[i - 1] | t2) == a[i - 1] && (t[i - 1] & t2) == b[i - 1]) {
                    t[i] = t2;
                    found = true;
                    break;
                }
            }
            if (!found) {
                possible = false;
                break;
            }
        }

        if (possible) {
            std::cout << "YES\n";
            for (int i = 0; i < n; i++) {
                std::cout << t[i] << " ";
            }
            return 0;
        }
    }

    std::cout << "NO\n";
    return 0;
}