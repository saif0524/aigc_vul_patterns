#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    long long neg = 0, pos = 0;
    for (int i = 0; i < n; i++) {
        int cur = 1;
        for (int j = i; j < n; j++) {
            cur *= (a[j] < 0)? -1 : 1;
            if (cur == -1) neg++;
            else if (cur == 1) pos++;
        }
    }
    std::cout << neg << " " << pos << std::endl;

    return 0;
}