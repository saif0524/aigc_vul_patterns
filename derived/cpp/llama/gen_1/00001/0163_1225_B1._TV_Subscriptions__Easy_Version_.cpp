#include <iostream>
#include <map>

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k, d;
        std::cin >> n >> k >> d;
        int a[n];
        for (int j = 0; j < n; j++) {
            std::cin >> a[j];
        }

        int minCount = k;
        for (int j = 0; j <= n - d; j++) {
            std::map<int, bool> countMap;
            for (int l = j; l < j + d; l++) {
                countMap[a[l]] = true;
            }
            if (countMap.size() < minCount) {
                minCount = countMap.size();
            }
        }

        std::cout << minCount << std::endl;
    }

    return 0;
}