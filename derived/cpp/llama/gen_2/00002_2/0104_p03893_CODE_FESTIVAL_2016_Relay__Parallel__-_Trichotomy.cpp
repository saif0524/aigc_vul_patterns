#include <iostream>
#include <vector>
#include <algorithm>

int f(int n) {
    if (n <= 2) return 0;
    int ans = 0;
    for (int i = 1; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - i - 1; j++) {
            int a = i, b = j, c = n - i - j;
            std::vector<int> v = {a, b, c};
            std::sort(v.begin(), v.end());
            ans = std::max(ans, 1 + f(v[1]));
        }
    }
    return ans;
}

int main() {
    int x;
    std::cin >> x;
    int ans = 0;
    for (int i = 1; ; i++) {
        if (f(i) == x) ans = i;
        else if (f(i) > x) break;
    }
    std::cout << ans << std::endl;
    return 0;
}