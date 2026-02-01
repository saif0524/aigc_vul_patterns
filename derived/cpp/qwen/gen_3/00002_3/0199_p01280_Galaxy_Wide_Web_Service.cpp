#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    while (std::cin >> N && N != 0) {
        int max_access = 0;
        for (int i = 0; i < N; ++i) {
            int d, t;
            std::cin >> d >> t;
            std::vector<int> q(d);
            for (int j = 0; j < d; ++j) {
                std::cin >> q[j];
            }
            max_access = std::max(max_access, *std::max_element(q.begin(), q.end()));
        }
        std::cout << max_access << std::endl;
    }
    return 0;
}