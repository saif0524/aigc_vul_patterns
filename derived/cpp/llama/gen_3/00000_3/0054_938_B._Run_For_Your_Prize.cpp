#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> prizes(n);
    for (int i = 0; i < n; i++) {
        std::cin >> prizes[i];
    }

    int my_pos = 1;
    int friend_pos = 10000000;
    int my_time = 0;
    int friend_time = 0;

    for (int pos : prizes) {
        int my_time_to_prize = std::abs(pos - my_pos);
        int friend_time_to_prize = std::abs(pos - friend_pos);

        if (my_time_to_prize <= friend_time_to_prize) {
            my_time += my_time_to_prize;
            my_pos = pos;
        } else {
            friend_time += friend_time_to_prize;
            friend_pos = pos;
        }
    }

    std::cout << std::max(my_time, friend_time) << std::endl;

    return 0;
}