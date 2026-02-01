#include <iostream>
#include <string>

int main() {
    std::string a, b;
    std::cin >> a >> b;
    int n;
    std::cin >> n;

    std::cout << a << " " << b << std::endl;

    for (int i = 0; i < n; i++) {
        std::string killed, replaced;
        std::cin >> killed >> replaced;

        if (killed == a) {
            a = replaced;
        } else {
            b = replaced;
        }

        std::cout << a << " " << b << std::endl;
    }

    return 0;
}