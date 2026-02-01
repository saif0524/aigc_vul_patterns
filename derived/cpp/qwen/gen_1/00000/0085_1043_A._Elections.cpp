#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int max_a = 0;
    int total_elodreip_votes = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        max_a = std::max(max_a, a[i]);
        total_elodreip_votes += a[i];
    }
    
    int k = max_a;
    while (true) {
        int total_awruk_votes = 0;
        for (int i = 0; i < n; ++i) {
            total_awruk_votes += k - a[i];
        }
        if (total_awruk_votes > total_elodreip_votes) {
            std::cout << k << std::endl;
            return 0;
        }
        ++k;
    }
}