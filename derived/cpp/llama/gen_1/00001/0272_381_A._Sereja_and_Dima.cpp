#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int s1 = 0, s2 = 0;
    int l = 0, r = n - 1;
    bool is_sereja = true;
    while (l <= r) {
        if (a[l] > a[r]) {
            if (is_sereja) {
                s1 += a[l];
            } else {
                s2 += a[l];
            }
            l++;
        } else {
            if (is_sereja) {
                s1 += a[r];
            } else {
                s2 += a[r];
            }
            r--;
        }
        is_sereja = !is_sereja;
    }
    std::cout << s1 << " " << s2 << std::endl;
    return 0;
}