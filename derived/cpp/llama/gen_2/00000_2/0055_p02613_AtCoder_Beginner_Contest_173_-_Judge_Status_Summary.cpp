#include <iostream>
#include <vector>
#include <string>

void solve() {
    int n;
    std::cin >> n;
    int ac = 0, wa = 0, tle = 0, re = 0;

    for (int i = 0; i < n; i++) {
        std::string str;
        std::cin >> str;

        if (str == "AC") {
            ac++;
        } else if (str == "WA") {
            wa++;
        } else if (str == "TLE") {
            tle++;
        } else if (str == "RE") {
            re++;
        }
    }

    std::cout << "AC x " << ac << std::endl;
    std::cout << "WA x " << wa << std::endl;
    std::cout << "TLE x " << tle << std::endl;
    std::cout << "RE x " << re << std::endl;
}

int main() {
    solve();
    return 0;
}