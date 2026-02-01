#include <iostream>
#include <cmath>

int main() {
    int c, v0, v1, a, l;
    std::cin >> c >> v0 >> v1 >> a >> l;

    int days = 1;
    int total_pages = v0;
    int current_speed = v0;

    while (total_pages < c) {
        current_speed = std::min(current_speed + a, v1);
        int pages_to_read = std::min(current_speed, c - total_pages);
        total_pages += pages_to_read - l;
        if (pages_to_read <= l) {
            break;
        }
        days++;
    }

    std::cout << days << std::endl;

    return 0;
}