#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);

    int q;
    std::cin >> q;
    std::cin.ignore();

    for (int i = 0; i < q; ++i) {
        int type;
        std::cin >> type;

        if (type == 1) {
            int pos;
            char c;
            std::cin >> pos >> c;
            --pos; // 0-indexed
            s[pos] = c;
        } else {
            int l, r;
            std::cin >> l >> r;
            --l; --r; // 0-indexed
            std::string y;
            std::cin >> y;

            int count = 0;
            for (int j = l; j <= r - y.size() + 1; ++j) {
                if (s.substr(j, y.size()) == y) {
                    ++count;
                }
            }

            std::cout << count << std::endl;
        }
    }

    return 0;
}