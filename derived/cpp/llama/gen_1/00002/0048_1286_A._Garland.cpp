#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> p(n);
    std::vector<int> odd, even;
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
        if (p[i] % 2 == 0 && p[i] != 0) {
            even.push_back(p[i]);
        } else if (p[i] % 2 == 1 && p[i] != 0) {
            odd.push_back(p[i]);
        }
    }

    std::sort(odd.begin(), odd.end());
    std::sort(even.begin(), even.end());

    int count = 0;
    int oddSize = odd.size();
    int evenSize = even.size();
    std::vector<int> final;
    for (int i = 0; i < n; i++) {
        if (p[i] == 0) {
            if (oddSize > evenSize || (oddSize == evenSize && oddSize > 0)) {
                final.push_back(odd.back());
                odd.pop_back();
                oddSize--;
            } else {
                final.push_back(even.back());
                even.pop_back();
                evenSize--;
            }
        } else {
            final.push_back(p[i]);
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (final[i] % 2 != final[i + 1] % 2) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}