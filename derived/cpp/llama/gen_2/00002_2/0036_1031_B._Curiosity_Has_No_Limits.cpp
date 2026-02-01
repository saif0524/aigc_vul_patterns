#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n - 1), b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        std::cin >> b[i];
    }

    for (int t1 = 0; t1 <= 3; t1++) {
        std::vector<int> t(n, -1);
        t[0] = t1;
        bool ok = true;
        for (int i = 0; i < n - 1; i++) {
            bool found = false;
            for (int t2 = 0; t2 <= 3; t2++) {
                if ((t[i] | t2) == a[i] && (t[i] & t2) == b[i]) {
                    t[i + 1] = t2;
                    found = true;
                    break;
                }
            }
            if (!found) {
                ok = false;
                break;
            }
        }
        if (ok) {
            std::cout << "YES" << std::endl;
            for (int i = 0; i < n; i++) {
                std::cout << t[i] << " ";
            }
            return 0;
        }
    }

    std::cout << "NO" << std::endl;
    return 0;
}