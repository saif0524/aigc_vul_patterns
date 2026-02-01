#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int q, x;
    std::cin >> q >> x;

    std::vector<int> a;
    for (int i = 0; i < q; i++) {
        int y;
        std::cin >> y;
        a.push_back(y);

        std::set<int> s;
        for (int j = 0; j < a.size(); j++) {
            int val = a[j] % x;
            s.insert(val);
        }

        int mex = 0;
        while (s.find(mex) != s.end()) {
            mex++;
        }

        int cnt = 0;
        for (int j = 0; j < a.size(); j++) {
            if (a[j] / x == 0) {
                cnt++;
            }
        }

        if (cnt > mex) {
            std::cout << mex + (cnt - mex) / (x + 1) * x + std::min((cnt - mex) % (x + 1), 1) << std::endl;
        } else {
            std::cout << mex << std::endl;
        }
    }

    return 0;
}