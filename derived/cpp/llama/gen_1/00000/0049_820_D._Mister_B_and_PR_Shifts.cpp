#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
        p[i]--;
    }

    int min_deviation = 1e9;
    int shift_id = -1;

    for (int k = 0; k < n; ++k) {
        int deviation = 0;
        std::vector<int> q = p;
        for (int i = 0; i < n; ++i) {
            int temp = (n - 1 - (q[i] - i + n) % n);
            deviation += temp * temp;
        }
        if (deviation < min_deviation) {
            min_deviation = deviation;
            shift_id = k;
        }
        p.push_back(p[0]);
        p.erase(p.begin());
    }

    std::vector<int> q = p;
    for (int i = 0; i < shift_id; ++i) {
        q.push_back(q[0]);
        q.erase(q.begin());
    }

    std::cout << min_deviation << " " << shift_id << std::endl;

    return 0;
}