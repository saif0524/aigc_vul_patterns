#include <iostream>

int64_t getSiz(int64_t i, int64_t z) {
    if (i == 1) return 2;
    if (i % (2 * z - 2) == 0) return 1;
    if (i % (2 * z - 2) <= z) return (i % (2 * z - 2));
    return (2 * z - 2) - (i % (2 * z - 2)) + 2;
}

int64_t getZ(int64_t l, int64_t r, int64_t z, int64_t a[]) {
    int64_t sum = 0;
    for (int64_t i = l; i <= r; i++) {
        sum += a[i - 1] * getSiz(i - l + 1, z);
    }
    return sum;
}

int main() {
    int64_t n;
    std::cin >> n;
    int64_t* a = new int64_t[n];
    for (int64_t i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int64_t m;
    std::cin >> m;
    for (int64_t i = 0; i < m; i++) {
        int64_t t;
        std::cin >> t;
        if (t == 1) {
            int64_t p, v;
            std::cin >> p >> v;
            a[p - 1] = v;
        }
        else if (t == 2) {
            int64_t l, r, z;
            std::cin >> l >> r >> z;
            std::cout << getZ(l, r, z, a) << std::endl;
        }
    }
    delete[] a;
    return 0;
}