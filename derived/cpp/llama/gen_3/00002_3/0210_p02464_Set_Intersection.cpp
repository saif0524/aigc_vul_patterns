#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::cin >> m;

    std::vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            i++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            std::cout << a[i] << std::endl;
            i++;
            j++;
        }
    }

    return 0;
}