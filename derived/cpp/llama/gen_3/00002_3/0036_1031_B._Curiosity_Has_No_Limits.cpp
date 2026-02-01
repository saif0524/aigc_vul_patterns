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

    bool found = false;
    for (int first = 0; first <= 3; first++) {
        std::vector<int> t(n);
        t[0] = first;
        bool ok = true;

        for (int i = 0; i < n - 1; i++) {
            bool foundNext = false;
            for (int next = 0; next <= 3; next++) {
                if ((t[i] | next) == a[i] && (t[i] & next) == b[i]) {
                    t[i + 1] = next;
                    foundNext = true;
                    break;
                }
            }
            if (!foundNext) {
                ok = false;
                break;
            }
        }

        if (ok) {
            found = true;
            std::cout << "YES\n";
            for (int i = 0; i < n; i++) {
                std::cout << t[i] << " ";
            }
            std::cout << "\n";
            break;
        }
    }

    if (!found) {
        std::cout << "NO\n";
    }

    return 0;
}