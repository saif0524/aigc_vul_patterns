#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::string status;
    std::cin >> status;

    int count = 0;
    for (int i = 0; i < n; i++) {
        bool can_show = true;
        for (int j = 0; j < n; j++) {
            if (i != j && status[j] == 'I') {
                can_show = false;
                break;
            }
        }
        if ((status[i] == 'A' || status[i] == 'I') && can_show) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}