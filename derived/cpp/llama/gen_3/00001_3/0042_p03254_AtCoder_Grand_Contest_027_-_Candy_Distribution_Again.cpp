#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, x;
    std::cin >> N >> x;

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < (1 << N); i++) {
        int sum = 0;
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                sum += a[j];
                cnt++;
            }
        }
        if (sum <= x) {
            ans = std::max(ans, cnt);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}